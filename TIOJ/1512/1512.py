heights = [0]
perm = []
ans = []
has = [0]
N = (int)(input())


for i in range(1, N + 1):
	x = (float)(input())
	heights.append(x)
	perm.append(i)
	has.append(0)

a = (int)(2)
a = a ** (N - 1)

print(a)

perm = sorted(perm, key = lambda x : heights[x])

ans.append(1)
has[1] = 1
for j in range(2, perm[N - 1]):
	if heights[ans[-1]] < heights[j]:
		ans.append(j)
		has[j] = 1

for j in range(N - 1, -1, -1):
	if has[perm[j]] == 0:
		ans.append(perm[j])



for i in range(0, N):
	print(ans[i])
