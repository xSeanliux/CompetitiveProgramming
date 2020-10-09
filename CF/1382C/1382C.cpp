#include <iostream>
#include <string.h>
#include <vector>
using namespace std; 

const int maxN = 2e5 + 226;

string _a, _b;
int N, fr, bk, inv, T, a[maxN], b[maxN];
vector<int> ans;

inline int abs(int x){
	return x < 0 ? -x : x;
}

inline void solve(){
	cin >> N >> _a >> _b;
	vector<int>().swap(ans);
	for(int i = 0; i < N; i++){
		a[i] = _a[i] - '0';
		b[i] = _b[i] - '0';
	}
	inv = false;
	fr = 0, bk = N - 1;
	for(int i = N - 1; i >= 0; i--){
		if(b[i] != (a[bk] ^ inv)){
			if(a[bk] != a[fr]){
				ans.push_back(1);
				a[fr] ^= 1;
			}
			inv ^= 1;
			swap(fr, bk);
			ans.push_back(abs(fr - bk) + 1);
		} 
		if(fr < bk){
			bk--;
		} else {
			bk++;
		}
	}
	cout << ans.size();
	for(int x : ans) cout << " " << x;
	cout << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}

}
