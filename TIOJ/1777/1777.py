inp = input().split()
N = (int)(inp[0])
L = (int)(inp[1])
R = (int)(inp[2])
ans = 0
for i in range(N):
	inp = input().split()
	pos = (int)(inp[0])
	direction = (int)(inp[1])
	if direction == 1 :
		ans = max(ans, pos - L)
	elif direction == 2:
		ans = max(ans, R - pos)
	else:
		ans = max(ans, min(pos - L, R - pos))

print((str)(ans))

