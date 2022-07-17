#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 326;
int C, T, N;
string s[maxN], a, b;

string inc(string s){
	if(s == "") return "1";
	reverse(s.begin(), s.end());	
	string res = "a";
	res[0] = (char)((s[0] + 1 - '0') % 10 + '0');
	int carry = (s[0] + 1 - '0') / 10;
	for(int i = 1; i < s.length(); i++){
		char c = s[i];
		if((carry + c - '0') >= 10){
			res += (char)(carry + c - 10);
			carry = 1;
		} else {
			res += (char)(carry + c);
			carry = 0;
		}
	}
	if(carry) res += '1';
	reverse(res.begin(), res.end());	
	return res;
}

inline void solve(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> s[i];
	int ans = 0;
	for(int i = 1; i < N; i++){
		a = s[i - 1], b = s[i];
		if(a.length() >= b.length()){
			bool f = true;
			for(int j = 0; j < b.length(); j++){
				if(a[j] < b[j]){ //fill with 0
					ans += a.length() - b.length();
					while(s[i].length() < s[i - 1].length()) s[i] += '0';
					f = false;
					break;
				} else if(a[j] > b[j]){
					ans += a.length() - b.length() + 1;
					while(s[i].length() < s[i - 1].length() + 1) s[i] += '0';
					f = false;
					break;
				}
			}
			if(f){
				string c = inc(a);
				if(c.length() == a.length() && c[b.length() - 1] == a[b.length() - 1]){
					ans += a.length() - b.length();
					s[i] = c;
				} else {
					ans += a.length() - b.length() + 1;
					while(s[i].length() < s[i - 1].length() + 1) s[i] += '0';
				}
			}
		} else continue;
	}
	cout << "Case #" << ++C << ": " << ans << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
