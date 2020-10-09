#include <iostream>
using namespace std;

int T, N;
bool res;

inline void solve(){
	cin >> N;
	if(N == 2){
		cout << "? 1" << endl;
		cin >> res;
		cout << "? 2" << endl;
		cin >> res;
		cout << "= " << (res ? "1" : "2") << endl;
		return;
	}
	if(N == 3){
		bool a, b;
		cout << "? 1" << endl;
		cin >> a;
		cout << "? 3" << endl;
		cin >> a;
		cout << "? 2" << endl;
		cin >> b;
		if(b){
			cout << "= 1" << endl;
			return;
		} else if(a){
			cout << "= 2" << endl;
			return;
		} else {
			cout << "= 3" << endl;
			return;
		}
	}
	int l = 0, r = N, m, dir = 1, pos = (N % 4 ? N / 4 + 1 : (N + 3) / 4);
	cout << "? " << pos << endl;
	cin >> res;
	while(l + 1 < r){
		m = (l + r) / 2;
		//cout << "m = " << m << endl;
		cout << "? " << pos + (dir ? m : -m) << endl;
		pos += (dir ? m : -m);
		cin >> res;
		dir ^= 1;
		if(res){
			r = m;
		} else {
			l = m;
		}
	}
	cout << "= " << r << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
