#include <iostream>
#include <vector>
using namespace std;

int N, T;
string s;

inline bool can(){
	int last = -100;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '1'){
			if(i - last <= 1) return false;
			last = i;
		}
	}
	return true;
}

inline void solve(){
	cin >> s;
	if(can()){
		cout << "YES\n";
		return;
	}
	for(int i = s.length() - 1; i >= 0; i--){
		if(s[i] == '1') s[i] = '0';
		else s[i] = '1';
		if(can()){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
