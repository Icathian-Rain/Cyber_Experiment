# 网安综合实践2
## 实验2 ARP缓存中毒


**重要更新**

    已将局域网中HostB修改为局域网外的Server2, 代码略有不同

### 目录：

    ./src/arp_request.py 用于发送arp请求
    ./src/arp_poisoning_mitm.py 用于arp欺骗双方
    ./src/mitm_attack_modify.py 中间人攻击，修改信息
    ./src/mitm_attack_monitor.py 中间人攻击，监听信息


### 使用方法:

**请确保使用前将本仓库参数修改为您的机器配置**
    
使用前请从受害机、攻击机 ping Server2，若ping不通，请打开虚拟机的防火墙

1、发送arp请求

1. 运行arp_request.py
2. 在目的机上输入arp -n 查看是否欺骗成功

2、arp欺骗

1. 运行arp_posisoning_mitm.py
2. 在受害机与服务器Server2上运行arp-n 查看是否欺骗成功

3、中间人攻击_监听

1. 攻击机运行arp_posisoning_mitm.py
2. 打开流量转发
3. 受害机和服务器开启nc
4. 关闭流量转发
5. 攻击机运行mitm_attack_monitor.py
6. 受害机发送信息
7. 攻击机终端输出通信信息

4、 中间人攻击_篡改

    步骤同中间人_监听，mitm_attack_monitor.py 替换为 mitm_attack_modify.py
    结果为指定字符串被替换为目的字符串


### 解释
- Server2 位于外网，若想从局域网192.168.60 ping通需打开虚拟机防火墙
- 中间人欺骗时，因Server2数据通过网关与受害机交流，因此需要欺骗网关
- 监听、篡改信息时，tcp数据包来自受害机，目的地为Server2 IP, 目的MAC地址为网关。