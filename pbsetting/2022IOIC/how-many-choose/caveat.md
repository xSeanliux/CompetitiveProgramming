//make sure: 

$T \leq 10^5$，$1 \le l \le r \le 10^{12}$，且 $1 \leq N \le 10^{12}$。
* $N \leq 44$ （$6\%$）
* $T = 1$（$18\%$）
* $r \leq 10^4$（$27\%$）
* 無額外限制（$49\%$）

gen.cpp: 		T MAXR MAXN
specific.cpp: 	T L R N
allsmall.cpp: 	T

Make sure: 

max tests for 1 ~ R, N
specific tests for some choose. 

//t1
specific 1 2 3 7 > $
gen 5 20 44 > $
gen 100000 1000000000000 44 > $
specific 3 1 1000000000000 44 > $
allsmall 100000 > $

//t2
specific 1 1000000000000 44 > $
specific 1 1000000000000 1000000000000 > $
specific 1 2 3 7 a > $
specific 1 38 7122 7122 a > $

//t3
gen 100000 10000 1000000000000 > $
specific 1 1 10000 44 > $
specific 1 1 10000 1000000000000 > $
specific 100000 1 10000 1000000000000 > $

//t4
gen 100000 1000000000000 1000000000000 > $
gen 100000 1000000000000 1000000000000 a > $
allsmall 100000 a > $