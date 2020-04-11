import requests
import pdb
ans = dict()

for num in range(1, 420002):
	url = "https://oeis.org/search?fmt=json&q=id:A" + str(num).zfill(6);
	res = requests.get(url).json()
	st = res["results"][0]["data"].split(',')
	print(st[0])
