#-*- coding: utf-8 -*-
import DH

if __name__ == '__main__':
    # 根据你的主机填写相关内容
    # 参数 host 本地主机，通常为0.0.0.0, port 本地端口
    server = DH.DHServer(host='0.0.0.0', port=8000)
    server.run()