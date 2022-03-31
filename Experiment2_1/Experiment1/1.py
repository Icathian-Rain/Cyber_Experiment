#! /usr/bin/python

from scapy.all import *

IP_A = '202.114.0.245'


def spoof_pkt(pkt):
	if pkt.haslayer(TCP) and pkt.haslayer(IP):
		print('-'*20)
		print("Source IP :", pkt[IP].src)
		print("Destination IP :", pkt[IP].dst)
		print("protocol :", pkt[IP].proto)
		print("src port", pkt[TCP].sport)
		print("dst port", pkt[TCP].dport)
		# pkt.show()


f = 'host ' + IP_A
sniff (iface = 'ens33',filter = f, prn=spoof_pkt)

