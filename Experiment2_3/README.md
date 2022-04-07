# 网安综合实践2
## 实验3 ICMP重定向攻击

### 目录:

    ./src/icmp_redirect.py 用于重定向
    ./src/mitm_attack.py 用于中间人欺骗

### 使用方法：

请将脚本文件中的参数修改为您的主机参数

1、重定向攻击


1. 配置基本网络环境，受害机A，攻击机C，网关gw, 服务器Server2
2. 看受害机，攻击机能否ping通 Server2, 若不能，请修改虚拟机的防火墙
3. 在受害机A终端ping Server2
4. 在攻击机运行icmp_redirect.py，请提前打开ipv4转发
5. 若受害机出现from : Redirect Host则为icmp重定向成功
   

2、中间人欺骗

1. 在重定向攻击基础上
2. 保持ipv4转发，分别在受害机和攻击机上打开nc通信
3. 关闭攻击机ipv4转发
4. 运行mitm_attack.py
5. 二者通讯
6. 服务器上出现的为修改后的字符串即为欺骗成功

