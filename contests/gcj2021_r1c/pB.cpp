#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define int long long int
using namespace std;
int c = 0;

inline bool isLargerEq(string &a, string &b){
	if(a.length() > b.length()) return true;
	if(a.length() < b.length()) return false;
	for(int i = 0; i < a.length(); i++) if(a[i] != b[i]) return a[i] > b[i];
	return true;
}

inline string getSeed(string &tgt, int init){
	string cur = "";
	//cout << "for tgt = " << tgt << ", seed = " << init;
	int cnt = 0;
	while(isLargerEq(tgt, cur) || cnt < 2){
		cur += to_string(init);	
		init++;
		cnt++;
	}
	//cout << ", cur = " << cur << endl;
	return cur;
}

inline void solve(){
	string s;
	cin >> s;
	vector<int> cand = vector<int>();
	if(s.length() == 1){
		cand.push_back(12);
	} else {
		int jizz = 1;
		for(int len = 1; len <= (s.length()); len++){
			cand.push_back(stoll(getSeed(s, jizz)));
			jizz *= 10;
			for(int k = 1; k < 20 && jizz > k; k++) cand.push_back(stoll(getSeed(s, jizz - k)));
		}
		for(int len = 1; len <= s.length() / 2 + 1; len++){
			int k = stoi(s.substr(0, len));
			cand.push_back(stoll(getSeed(s, k)));
			k++;
			cand.push_back(stoll(getSeed(s, k)));
			string ns = to_string(k) + "0";
			k *= 10;
			while(ns.size() <= (s.length()) / 2){
				cand.push_back(stoll(getSeed(s, k)));
				ns += "0";
				k *= 10;
			}
		}
		//remember the length + 1!
		sort(cand.begin(), cand.end());
	}
	cout << "Case #" << ++c << ": " << cand[0] << endl;
}

signed main(){
	int curr = 1;
	//solve(to_string(10));
	//for(int i = 1; i <= 10000; i++) solve(to_string(i));
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
}



