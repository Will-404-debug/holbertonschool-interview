#!/usr/bin/python3
"""
Main file for testing UTF-8 validation function
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data1 = [65]
print(validUTF8(data1))  # True (ASCII 'A')

data2 = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data2))  # True ("Python is cool!")

data3 = [229, 65, 127, 256]
print(validUTF8(data3))  # False (invalid UTF-8 bytes)
