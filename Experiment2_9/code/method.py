# -*- coding: utf-8 -*-
import random
import time


def power(x, y, p):
    """
    x^y % p
    """
    res = 1
    x = x % p
    while (y > 0):
        if (y & 1):
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

def is_prime(n):
    """
    判断是否为素数
    """
    if n == 2:
        return True
    if n < 2 or n % 2 == 0:
        return False
    for _ in range(3, int(n ** 0.5) + 2, 2):
        if n % _ == 0:
            return False
    return True

def genNbitsPrime(n):
    """
    生成n位的素数
    """
    while True:
        num = random.randint(0, (1 << n) - 1)
        if is_prime(num):
            return num

def get_generator(p):
    """
    获取本原根
    """
    a = 2
    while True:
        if power(a, p-1, p) == 1:
            num = 2
            flag = True
            while num < p-1:
                if power(a, num, p) == 1:
                    flag = False
                    break
                num += 1
            if flag:
                return a
        a += 1

def get_cal(a, p, rand):
    """
    计算 a^rand % p
    """
    return power(a, rand, p)

def get_key(cal_A, cal_B, p):
    """
    生成密钥
    """
    return power(cal_A, cal_B, p)



if __name__ == "__main__":
    print(hex(get_generator(genNbitsPrime(8))))