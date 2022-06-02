# DH portol Desigin

## header

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

## data

### HANDSHAKE_REQUEST 

| 名称 | 长度(Byte) |
| ---- | ---------- |
| AUTH | 不定       |

### HANDSHAKE_REPLY

| 名称 | 长度(BYTE)               |
| ---- | ------------------------ |
| p    | DEFAULT_KEY_BYTES_LENGTH |
| g    | DEFAULT_KEY_BYTES_LENGTH |
| AUTH | 不定                     |

### CONFIRM_SHARED

| 名称 | 长度                     |
| ---- | ------------------------ |
| ya   | DEFAULT_KEY_BYTES_LENGTH |

### CONFIRM_CAL

| 名称 | 长度                     |
| ---- | ------------------------ |
| yb   | DEFAULT_KEY_BYTES_LENGTH |
