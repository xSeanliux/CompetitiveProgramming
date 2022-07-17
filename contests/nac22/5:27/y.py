import time
import hashlib
from sys import stdin
"""
12/31/2023 18:52:35 BEROT2WTNL2ZZJQJDGEIC2TRWDQGXK2W
01/29/2024 12:30:00 CSIGU6O3PH3W2NS3OVWY4KCT6M======


999250
448651
"""

#T = (Current Unix time - T0) / X

def binary2int(binary): 
    int_val, i, n = 0, 0, 0
    while(binary != 0): 
        a = binary % 10
        int_val = int_val + a * pow(2, i) 
        binary = binary//10
        i += 1
    return int_val

def _hmac_sha1(input_str, key):
    raw = input_str.encode("utf-8")
    key = key.encode('utf-8')
    hashed = hmac.new(key, raw, hashlib.sha1)
    return base64.encodebytes(hashed.digest()).decode('utf-8')

def HOTP(K, T):
  hash = _hmac_sha1(K, T)
for line in stdin:
  data = line.split(' ')
  date = data[0] + ' ' + data[1]
  seed = line[2]
  print(date)
  struct_time = time.strptime(date, "%m/%d/%Y %H:%M:%S")
  T = (struct_time-datetime.datetime(1970,1,1)).total_seconds()
  X = int(T) // 30
  print(struct_time.time())
  truncate()

