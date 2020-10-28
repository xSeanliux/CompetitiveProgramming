#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326;
int N, A, B, arr[maxN], oarr[maxN];

inline bool check(int x){
	for(int i = 0; i < N; i++) arr[i] = oarr[i];
	for(int i = 0; i < N; i++) arr[i] -= x * B;
	int chk = 0;
	for(int i = 0; i < N; i++){
		if(arr[i] > 0){
			chk += (arr[i] + (A - B) - 1) / (A - B);
		}
	}
	return chk <= x;
}

signed main(){
	cin >> N >> A >> B;
	for(int i = 0; i < N; i++) cin >> oarr[i];
	int l = 0, r = 1e10, m;
	while(r - l > 1){
		m = (l + r) / 2;
		if(check(m)){
			r = m;	
		} else {
			l = m;
		}
	}
	cout << r << endl;
}
