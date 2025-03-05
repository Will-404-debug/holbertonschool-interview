#!/usr/bin/python3
"""
UTF-8 Validation Module

This module contains a function `validUTF8(data)` that checks whether
a given dataset represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    :param data: List of integers representing bytes
    :return: True if data is a valid UTF-8 encoding, else False
    """
    num_bytes = 0  # Tracks number of bytes remaining in the UTF-8 character

    for byte in data:
        byte = byte & 0xFF  # Consider only the 8 least significant bits

        if num_bytes == 0:
            # Determine the number of bytes for the current character
            if (byte >> 7) == 0b0:  # 1-byte character (0xxxxxxx)
                continue
            elif (byte >> 5) == 0b110:  # 2-byte character (110xxxxx)
                num_bytes = 1
            elif (byte >> 4) == 0b1110:  # 3-byte character (1110xxxx)
                num_bytes = 2
            elif (byte >> 3) == 0b11110:  # 4-byte character (11110xxx)
                num_bytes = 3
            else:
                return False  # Invalid leading byte
        else:
            # Check that the byte is a valid continuation byte (10xxxxxx)
            if (byte >> 6) != 0b10:
                return False
            num_bytes -= 1

    return num_bytes == 0  # Ensure all characters are fully validated
