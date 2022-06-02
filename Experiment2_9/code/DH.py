#-*- coding: utf-8 -*-
from method import *
import socket
import time

# header
# magic 
MAGIC = b'DH'
# 版本号
VERSION = b'\x01'
# 缓冲区大小
DEFAULT_BUFFER_SIZE = 1024
# 质数p的字节位数
DEFAULT_KEY_BYTES_LENGTH = 2

# 验证信息
A_AUTH = 'u202012043_A'
B_AUTH = 'u202012043_B'

# DH 协议类型
# \x01 HANDSHAKE_REQUEST
# \x02 HANDSHAKE_REPLY
# \x03 CONFIRM_SHARED
# \x04 CONFIRM_CAL
DHTYPE = [b'', b'\x01', b'\x02', b'\x03', b'\x04']



class DHProto:
    # 报文类型判断    
    def is_handshake_request(self, pkt_data):
        if len(pkt_data) > 4 and pkt_data[:2] == MAGIC and pkt_data[2:3] == VERSION and pkt_data[3:4] == DHTYPE[1]:
            return True
        return False

    def is_handshake_reply(self, pkt_data):
        if len(pkt_data) > 4 and pkt_data[:2] == MAGIC and pkt_data[2:3] == VERSION and pkt_data[3:4] == DHTYPE[2]:
            return True
        return False

    def is_confirm_shared(self, pkt_data):
        if len(pkt_data) > 4 and pkt_data[:2] == MAGIC and pkt_data[2:3] == VERSION and pkt_data[3:4] == DHTYPE[3]:
            return True
        return False

    def is_confirm_cal(self, pkt_data):
        if len(pkt_data) > 4 and pkt_data[:2] == MAGIC and pkt_data[2:3] == VERSION and pkt_data[3:4] == DHTYPE[4]:
            return True
        return False

# Server端
class DHServer(DHProto):
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((host, port))

    def handle_handshake_request(self, pkt_data):
        # handshake_request响应
        if pkt_data[4:].decode('utf-8') == A_AUTH:
            print("handshake_request from A")
            return True
        else:
            print("auth ERROR!")
            return False

    def send_handshake_reply(self, addr):
        
        header = MAGIC + VERSION + DHTYPE[2]
        print("waiting for prime p")
        self.p = genNbitsPrime(DEFAULT_KEY_BYTES_LENGTH * 8)
        print("got prime p={}".format(self.p))
        self.g = get_generator(self.p)
        data = int.to_bytes(self.p, int(DEFAULT_KEY_BYTES_LENGTH), byteorder = 'big')
        data += int.to_bytes(self.g, int(DEFAULT_KEY_BYTES_LENGTH), byteorder = 'big')
        data += bytearray(B_AUTH, encoding='utf-8')
        self.sock.sendto(header + data, addr)

    def handle_confirm_shared(self, pkt_data):
        print("confirm_shared from A")
        self.b = random.randint(1, self.p - 1)
        self.yb = get_cal(self.g, self.p, self.b)
        self.ya = int.from_bytes(pkt_data[4:], byteorder = 'big')
        self.key = get_key(self.ya, self.yb, self.p)

    def send_confirm_cal(self, addr):
        header = MAGIC + VERSION + DHTYPE[4]
        data = int.to_bytes(self.yb, DEFAULT_KEY_BYTES_LENGTH, byteorder = 'big')
        self.sock.sendto(header + data, addr)

    def run(self):
        while True:
            try:
                pkt_data, addr = self.sock.recvfrom(DEFAULT_BUFFER_SIZE)
                if self.is_handshake_request(pkt_data):
                    self.handle_handshake_request(pkt_data)
                    time.sleep(1)
                    self.send_handshake_reply(addr)
                elif self.is_confirm_shared(pkt_data):
                    self.handle_confirm_shared(pkt_data)
                    time.sleep(1)
                    self.send_confirm_cal(addr)
                    print('-------------DH finished------------------------')
                    print("p={}, g={}, b={}, ya={}, yb={}\nkey={}".format(self.p, self.g, self.b, self.ya, self.yb, self.key))
                    break
            except socket.timeout:
                print("timeout")
                continue
            except Exception as e:
                print(e)
                continue
        print("Down")



class DHClient(DHProto):
    def __init__(self, host, port, dst_addr):
        self.dest_addr = dst_addr
        self.host = host
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((host, port))

    def send_handshake_request(self, addr):
        header = MAGIC + VERSION + DHTYPE[1]
        data = A_AUTH.encode('utf-8')
        self.sock.sendto(header + data, addr)

    def handle_handshake_reply(self, pkt_data):
        if pkt_data[4+DEFAULT_KEY_BYTES_LENGTH*2:].decode('utf-8') == B_AUTH:
            print("handshake_reply from B")
            self.p = int.from_bytes(pkt_data[4:4+DEFAULT_KEY_BYTES_LENGTH], byteorder = 'big')
            self.g = int.from_bytes(pkt_data[4+DEFAULT_KEY_BYTES_LENGTH:4+DEFAULT_KEY_BYTES_LENGTH*2], byteorder = 'big')
            self.a = random.randint(1, self.p - 1)
            self.ya = get_cal(self.g, self.p, self.a)
            return True
        else:
            print("auth ERROR!")
            return False

    def send_confirm_shared(self, addr):
        header = MAGIC + VERSION + DHTYPE[3]
        data = int.to_bytes(self.ya, int(DEFAULT_KEY_BYTES_LENGTH), byteorder = 'big')
        self.sock.sendto(header + data, addr)

    def handle_confirm_cal(self, pkt_data):
        print("confirm_cal from B")
        self.yb = int.from_bytes(pkt_data[4:],byteorder = 'big')
        self.key = get_key(self.ya, self.yb, self.p)
        return True



    def run(self):
        self.send_handshake_request(self.dest_addr)
        while True:
            try:
                pkt_data = self.sock.recv(DEFAULT_BUFFER_SIZE)
                if self.is_handshake_reply(pkt_data):
                    if self.handle_handshake_reply(pkt_data):
                        time.sleep(1)
                        self.send_confirm_shared(self.dest_addr)
                elif self.is_confirm_cal(pkt_data):
                    self.handle_confirm_cal(pkt_data)
                    print('-------------DH finished------------------------')
                    print("p={}, g={}, a={}, ya={}, yb={}\nkey={}".format(self.p, self.g, self.a, self.ya, self.yb, self.key))
                    break
                else:
                    print("ERROR!")
            except socket.timeout:
                print("timeout")
                continue
            except Exception as e:
                print(e)
                continue
        print("Down")