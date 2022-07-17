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
	while(isLargerEq(tgt, cur)){
		cur += to_string(init);	
		init++;
	}
	//cout << ", cur = " << cur << endl;
	return cur;
}

inline string getAns(string &s){
	vector<string> cand = vector<string>();
	if(s.length() == 1){
		cand.push_back("12");
	} else {
		for(int len = 1; len < s.length(); len++){
			cand.push_back(getSeed(s, stoi(s.substr(0, len))));
			cand.push_back(getSeed(s, stoi(s.substr(0, len)) + 1));
		}
		//remember the length + 1!
		sort(cand.begin(), cand.end(), [](string &a, string &b){
			if(a.length() < b.length()) return true;
			if(a.length() > b.length()) return false;
			for(int i = 0; i < a.length(); i++) if(a[i] != b[i]) return a[i] < b[i];
			return true;
		});
	}
	return cand[0];
}

inline void solve(int N){
	string s;
	//int N;
	//cin >> N;
	s = to_string(N);
	vector<string> cand = vector<string>();
	string cur = "99999999999", news = "";
	for(int i = 1; i * i <= N; i++){
		news = getSeed(s, i);
		if(isLargerEq(cur, news)) cur = news;
	}
	cout << "Case #" << ++c << ": " << cur << endl;
}

signed main(){
	for(int i = 1; i <= 10000; i++) solve(i);
	/*
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	*/
}



