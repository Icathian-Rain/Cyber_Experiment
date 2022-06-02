#-*- coding: utf-8 -*-
import DH

if __name__ == '__main__':
    server = DH.DHServer(host='127.0.0.1', port=8000)
    server.run()