while(True):
	n = (input())
	if(n == ""):
		break
	n = n.split()
	a = n[1]
	n = (int)(n[0])
	A = O = R = 0
	if n % 2 == 0:
		R = (n // 2) * (n - 2)
	O = n * ((n - n//2 - 2) * (n - n//2 - 1) // 2)
	A = n * (n - 1) * (n - 2) // 6 - O - R
	if a[0] == 'R':
		print(R)
	elif a[0] == 'A':
		print(A)
	else:
		print(O)