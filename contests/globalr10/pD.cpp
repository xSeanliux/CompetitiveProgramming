#include <iostream>
#include <string.h>
#include <deque>
#define int long long int
using namespace std;

int T, N;
string s;

inline void solve(){
	cin >> N >> s;
	deque<char> dq;
	for(char c : s){
		dq.push_back(c);
	}
	int jizz = 0;
	while(dq.front() == dq.back() && jizz < N + 5){
		dq.push_front(dq.back());
		dq.pop_back();
		jizz++;
	}
	//cout << "jizz = " << jizz << endl;
	if(jizz > N){ //all the same char
		if(N % 3 == 0){
			cout << N / 3 << endl;
		} else if(N % 3 == 1){
			cout << N / 3 + 1 << endl;
		} else {
			cout << N / 3 + 1 << endl;
		}
		return;
	}
	int ans = N + 326;
	char cur = ',';
	int cnt = 0, _ans = 0;
	for(int i = 0; i < N; i++){
		if(dq[i] == cur){
			cnt++;
		} else {
			_ans += cnt / 3;
			cnt = 1;
		}
		cur = dq[i];
	}
	_ans += cnt / 3;
	ans = min(ans, _ans);
	dq.push_back(dq.front());
	dq.pop_front();
	cout << ans << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
