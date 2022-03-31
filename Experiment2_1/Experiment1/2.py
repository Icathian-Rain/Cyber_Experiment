from scapy.all import *

inRoute = True
i = 1
while inRoute:
	a = IP(dst='101.42.233.20', ttl=i)
	response = sr1(a/ICMP(),timeout=7,verbose=0)
	
	if response is None:
		print ("%d Request timed out." % i)
	elif response.type == 0:
		print ("%d {%s}" % (i, response.src))
		inRoute = False
	else:
		print ("%d %s" % (i, response.src))
		# response.show()

	i = i + 1
