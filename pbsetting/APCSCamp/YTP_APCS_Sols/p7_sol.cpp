#include <iostream>
#define int long long int 
using namespace std;
const int M = 1e9 + 7, I2 = 5e8 + 4;

inline int mult(int a, int b){
	return ((a % M) * (b % M)) % M;
}

inline int isum(int l, int r){ //returns $\sum_{k = l}^{r} k \mod M$
	int res = (mult(r, r + 1) - mult(l, l - 1) + M) % M;
	return res * I2 % M;
}

inline int sum(int x){
	if(x <= 1) return x;
	int s = mult(x, x + 1);
	for(int i = 1; i <= x; i++){
		//for all $t \in [i,\, \floor{\frac{x}{\floor{\frac{x}{i}}}}]$, $\floor{\frac{x}{t}}$ is the same.
		int l = i;
		int r = (x / (x / i));
		s = (s - mult(x / l, isum(l, r)) + M) % M;
		i = r;

	}
    return s;
}

signed main() {
	int L, R;    
	cin >> L >> R;
	cout << (sum(R) - sum(L - 1) + M) % M << endl;
}
