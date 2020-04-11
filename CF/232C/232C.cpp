#include <iostream>
#include <iostream>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;
 
int a, b, Q, N, fib[100];
 
int toLast(int x, int N);
int toFirst(int x, int N);
map<pii, int> tl, tf;
 
 
int dist(int a, int b, int N){
	//cout << "Running dist(" << a << ", " << b << ", " << N << ")\n";
	if(N <= 2) return !(a == b);
	if(a > b) swap(a, b);
	if(a <= fib[N - 1] && b <= fib[N - 1]){
		int d1 = dist(a, b, N - 1);	
		int d2 = min(toFirst(a, N - 1), toLast(a, N - 1)) + min(toFirst(b, N - 1), toLast(b, N - 1)) + 2;
		return min(d1, d2);
	} 
	if(a > fib[N - 1] && b > fib[N - 1]){
		return dist(a - fib[N - 1], b - fib[N - 1], N - 2);
	}
	return min(toFirst(a, N - 1), toLast(a, N - 1)) + toFirst(b - fib[N - 1], N - 2) + 1;
}
 
signed main(){
	fib[0] = 1;
	fib[1] = 2;
	for(int i = 2; fib[i - 1] < 1e16; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	cin >> Q >> N;
	N = min(N, (int)77);
	while(Q--){
		cin >> a >> b;
		cout << dist(a, b, N) << endl;
		tl = map<pii, int>();
		tf = map<pii, int>();
	}
}
 
int toFirst(int x, int N){
	if(x == 1) return 0;
	if(tf.count({x, N})) return tf[{x, N}];
	if(N == 1) return x != 1;
	if(!N) return 0;
	if(x <= fib[N - 1]){
		tf[{x, N}] = toFirst(x, N - 1);
	} else {
		tf[{x, N}] = 1 + toFirst(x - fib[N - 1], N - 2);
	}
	return tf[{x, N}];
}
 
int toLast(int x, int N){
	if(x == fib[N]) return 0;
	if(tl.count({x, N})) return tl[{x, N}];
	if(N == 1) return x == 1;
	if(!N) return 0;
	if(x <= fib[N - 1]){
		tl[{x, N}] = 1 + toLast(x, N - 1) + (N - 1) / 2;
	} else {
		tl[{x, N}] = toLast(x - fib[N - 1], N - 2);
	}
	return tl[{x, N}];
}
