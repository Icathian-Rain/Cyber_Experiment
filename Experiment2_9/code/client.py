#-*- coding: utf-8 -*-
import DH

if __name__ == '__main__':
    # 根据你的主机填写相关内容
    # 参数 host 本地主机，通常为0.0.0.0，参数 port 本地端口, dst_addr (目标主机ip, 目标主机端口)
    client = DH.DHClient(host='0.0.0.0', port=1234 ,dst_addr=('127.0.0.1', 8000))
    client.run()