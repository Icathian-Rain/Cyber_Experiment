# 网安实践针 对DH密钥交换的中间人攻击实验

## DH秘钥协商的协议 DH portol Desigin

### header

| 名称    | 长度(Byte) | 可选项  |
| ------- | ---------- | ------- |
| MAGIC   | 2          | b'DH'   |
| VERSION | 1          | b'\x01' |
| DHType  | 1          | b'\x01' |

DHType 类型： 

'\x01' = HANDSHAKE_REQUEST 

'\x02' = HANDSHAKE_REPLY 

'\x03' = CONFIRM_SHARED 

'\x04' = CONFIRM_CAL

### data

#### HANDSHAKE_REQUEST 

| 名称 | 长度(Byte) |
| ---- | ---------- |
| AUTH | 不定       |

#### HANDSHAKE_REPLY

| 名称 | 长度(BYTE)               |
| ---- | ------------------------ |
| p    | DEFAULT_KEY_BYTES_LENGTH |
| g    | DEFAULT_KEY_BYTES_LENGTH |
| AUTH | 不定                     |

#### CONFIRM_SHARED

| 名称 | 长度                     |
| ---- | ------------------------ |
| ya   | DEFAULT_KEY_BYTES_LENGTH |

#### CONFIRM_CAL

| 名称 | 长度                     |
| ---- | ------------------------ |
| yb   | DEFAULT_KEY_BYTES_LENGTH |

## 实验 1-2 通讯建立

### 1-2-1 前期工作

定义一系列常用数学函数

见method.py

### 1-2-2 DH协议主体部分

见 DH.py(无需修改)

### 1-2-3 client.py server.py

根据自身需求设定host, port, dst_addr

`client.py`

```python
client = DH.DHClient(host='0.0.0.0', port=1234 ,dst_addr=('10.0.2.7', 8000))
# 10.0.2.7 替换为你的目的主机ip
```

`server.py`

```python
# 参数 host 本地主机，通常为0.0.0.0, port 本地端口
# 一般无需修改
server = DH.DHServer(host='0.0.0.0', port=8000)
```



### 1-2-4 运行

将完整code文件夹移动至HostA 与 Server2上

先在Server2上运行

`python3 server.py`

后在HostA上运行

`python3 client.py`

结果示意图

Server2上:

![image-20220604100448831](https://img.icathianrain.icu/images/2022/06/03/image-20220604100448831.png)

HostA上:

![image-20220604100459414](https://img.icathianrain.icu/images/2022/06/03/image-20220604100459414.png)

## 实验1-3 中间人攻击

HostA，Server2无需修改

将code 文件夹完整移动至HostM上

HostM实验步骤

- 根据实际ip, mac地址修改arp_poisoning_mitm.py 内容

![image-20220604095609253](https://img.icathianrain.icu/images/2022/06/03/image-20220604095609253.png)

- 根据实际ip, mac地址修改mitm_attack_modify.py 内容

![image-20220604095759858](https://img.icathianrain.icu/images/2022/06/03/image-20220604095759858.png)

- 在HostM上

> 运行arp_poisoning_mitm.py
>
>  `python arp_poisoning_mitm.py `
>
>  关闭IP转发
>
> echo 0 >/proc/sys/net/ipv4/ip_forward
>
> 运行mitm_attack_modify.py
>
> `python3 mitm_attack_modify.py`

先在Server2上运行

`python3 server.py`

后在HostA上运行

`python3 client.py`



结果示意图:

HostA:

![image-20220604100311601](https://img.icathianrain.icu/images/2022/06/03/image-20220604100311601.png)

Server2:

![image-20220604100329035](https://img.icathianrain.icu/images/2022/06/03/image-20220604100329035.png)

HostM:

![image-20220604100353093](https://img.icathianrain.icu/images/2022/06/03/image-20220604100353093.png)
