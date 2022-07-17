import hmac, base64, struct, hashlib
import datetime
import time
import hashlib
from sys import stdin

def hotp(key, counter, digits=6, digest='sha1'):
    key = base64.b32decode(key.upper() + '=' * ((8 - len(key)) % 8))
    counter = struct.pack('>Q', counter)
    mac = hmac.new(key, counter, digest).digest()
    offset = mac[-1] & 0x0f
    binary = struct.unpack('>L', mac[offset:offset+4])[0] & 0x7fffffff
    return str(binary)[-digits:].zfill(digits)


def totp(key, time_in_seconds, time_step=30, digits=6, digest='sha1'):
    return hotp(key, int(time_in_seconds // time_step), digits, digest)

#base64 encoded key

ans = []

for line in stdin:
  if(len(line) < 10):
    continue
  data = line.split(' ')
  data = [x for x in data if len(x.strip()) > 0]
  #print(data)
  date = data[0] + ' ' + data[1]
  seed = ""
  if(data[-1][-1] == '\n'):
    seed = data[-1][:-1]
  else:
    #print('nolendlf')
    seed = data[-1]
  #seed = seed + (b'=' * (-len(seed) % 4))
  struct_time = time.strptime(date, "%m/%d/%Y %H:%M:%S")
  time_in_seconds = int(time.mktime(struct_time) - time.mktime(time.strptime("01/01/1970 00:00:00", "%m/%d/%Y %H:%M:%S")))
  #print(time_in_seconds)
  ans.append(totp(seed, time_in_seconds))

print('\n'.join(ans))