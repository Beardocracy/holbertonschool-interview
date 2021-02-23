#!/usr/bin/python3
""" Contains method for UTF-8 validation """


def validUTF8(data):
    """Validates an int array for UTF-8"""
    o_data = []
    for i in data:
        o_data.append(i & 0b11111111)
    byte_arr = bytes(o_data)
    try:
        byte_arr.decode()
    except UnicodeDecodeError:
        return False

    return True
