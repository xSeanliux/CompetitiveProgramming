#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326;
bool isIn[maxN];
int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

inline void solve(){
	int N;
	cin >> N;
	int cp = 1, cnt = 0;
	for(int i = 1; i < N; i++){
		if(gcd(i, N) == 1){
			isIn[i] = true;
			cnt++;
			cp = cp * i % N;
		}
	}
	if(cp == 1){
		cout << cnt << endl;
		for(int i = 1; i < N; i++) if(isIn[i]) cout << i << " ";
		cout << endl;
	} else {
		cout << cnt - 1 << endl;
		for(int i = 1; i < N; i++) if(isIn[i] && (cp != i)) cout << i << " ";
		cout << endl;
	}
}

signed main(){
	solve();	
}
