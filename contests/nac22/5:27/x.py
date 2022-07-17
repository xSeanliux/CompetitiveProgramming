# Hash a single string with hashlib.sha256
import hashlib
from sys import stdin

"""
a_string = 'this string holds important and private information'
hashed_string = hashlib.sha256(a_string.encode('utf-8')).hexdigest()
print(hashed_string)
# Returns:
# 4e7d696bce894548dded72f6eeb04e8d625cc7f2afd08845824a4a8378b428d1

init_key
Args -
RND          (16 bit random number)
ID_NUM       (8 bit user ID)
--
NUM = RND(left shift 16) OR ID_NUM    // a 16 bit number
BYTES = bytes(NUM)         // 4 bytes little-endian
return SHA256_HASH(BYTES)  // see your language's hash library

key_schedule
Args -
RND          (16 bit random number)
OLD_KEY      (256 bit old key)
--
CAT_RND = 0     // concatenate the binary of RND back to back so its 256 bits long
for i in {1,2,...,16} do
        CAT_RND = CAT_RND OR RND(leftshift 16*i bits)
return SHA256_HASH(CAT_RND XOR OLD_KEY) // this is your new key

"""
def rand(state, seed):
  rnd = 0
  for i in range(16):
    response = (state & 1) ^ ((state & (1<<4)) >> 4) ^ ((state & (1<<10)) >> 10) ^ ((state & (1<<11)) >> 11)
    state = (state >> 1) | (response << 12)
    rnd = (rnd << 1) | response
  return rnd, state

def reverse(a):
    arr = [((a >> i) & 0xf) for i in (0, 4, 8, 12)]
    b = 0
    for x in arr:
      b = (b << 4) + x
    return b

def init_key(rnd, id):
  num = (rnd << 16) | id
  _bytes = num.to_bytes(4, 'little')
  #print(_bytes)
  return hashlib.sha256(_bytes).hexdigest()

def key_schedule(rnd, old_key):
  cat_rnd = 0
  old_key = int(old_key, 16)
  #old_key = bytes.fromhex(old_key)
  for i in range(0, 16):
    #CAT_RND = CAT_RND OR RND(leftshift 16*i bits)
    cat_rnd = cat_rnd | (rnd << (16 * i))
  # return SHA256_HASH(CAT_RND XOR OLD_KEY) // this is your new key
  #cat_rnd = cat_rnd.to_bytes(256, 'big')
  #old_key = bytes.fromhex(old_key)
  num = cat_rnd ^ old_key
  num = num.to_bytes(32, 'little')
  #num = bytearray.fromhex('{:0064}'.format(num))
  return hashlib.sha256(num).hexdigest()


for line in stdin:
  nums = line.split(' ')
  seed = int(nums[0])
  id   = int(nums[1])
  state = (seed << 6) | seed
  for i in range(42):
    rnd, state = rand(state, seed)
  rnd, state = rand(state, seed)
  key = []
  key.append(init_key(rnd, id))
  rnd, state = rand(state, seed)
  key.append(key_schedule(rnd, key[-1]))
  rnd, state = rand(state, seed)
  key.append(key_schedule(rnd, key[-1]))
  rnd, state = rand(state, seed)
  key.append(key_schedule(rnd, key[-1]))
  rnd, state = rand(state, seed)
  key.append(key_schedule(rnd, key[-1]))
  rnd, state = rand(state, seed)
  key.append(key_schedule(rnd, key[-1]))
  print(' '.join(key[1:]))