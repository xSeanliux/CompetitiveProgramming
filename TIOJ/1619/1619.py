n = int(input())

a = input().split()
b = input().split()

def getAns(l, r):
	if(l + 1 == r):
		return (int(a[l]) + int(b[l]))
	m = (l + r) // 2
	return getAns(l, m) * getAns(m, r)

for i in range(n):
	a[i] = int(a[i])
	b[i] = int(b[i])

a.sort()
b.sort()
b = list(reversed(b))

print(getAns(0, n))

