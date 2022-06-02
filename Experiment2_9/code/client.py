#-*- coding: utf-8 -*-
import DH

if __name__ == '__main__':
    client = DH.DHClient(host='127.0.0.1', port=1234 ,dst_addr=('127.0.0.1', 8000))
    client.run()