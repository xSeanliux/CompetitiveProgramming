#include <iostream>
#define int long long int
using namespace std;

int T, N, c;

inline int bc(int x){
	int r = 0;
	while(x){
		r++;
		x -= (x & -x);
	}
	return r;
}

inline void solve(){
	cin >> N;
	cout << "Case #" << ++c << ":\n";
	int l, k;
	for(l = 1;; l++){
		for(k = 0; k <= l; k++){
			if(N < (1 << l) && N >= (l - k) && bc(N - (l - k)) == k){
				//do thing
				bool st = 0;
				for(int r = 0; r < l; r++){
					cout << r + 1 << " " << 1 + (st ? r : 0) << endl; 	
					if(((N - (l - k)) >> r) & 1){
						if(st == 0){
							for(int t = 1; t <= r; t++){
								cout << r + 1 << " " << t + 1 << endl;
							}
						} else {
							for(int t = r - 1; t >= 0; t--){
								cout << r + 1 << " " << t + 1 << endl;
							}
						}
						st ^= 1;
					}
				}
				return;
			}
		}
	}
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
