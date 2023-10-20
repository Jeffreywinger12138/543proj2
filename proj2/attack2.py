#!/usr/bin/env python2
hex_string = "12345678"
hex_bytes = bytes.fromhex(hex_string)

# Reverse the byte order to make it little-endian
little_endian_bytes = hex_bytes[::-1]

# Decode the little-endian bytes to a UTF-8 string
decoded_string = little_endian_bytes.decode('utf-8')
your_buffer =  "A" * 108 + decoded_string
# YOUR CODE: Generate buf appropriately
print(your_buffer)