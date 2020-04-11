#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<string> res, parts[226], _r, pres, sufs;
int N, T, c;
string s;

vector<string> part(string s){
	string cs = "";	
	res.clear();
	for(char c : s){
		if(c == '*'){
			res.push_back(cs);
			cs = "";
		} else {
			cs += c;
		}
	}
	res.push_back(cs);
	return res;
}

inline void solve(){
	cin >> N;
	for(int i = 0; i <= N; i++) parts[i].clear();
	pres.clear();
	sufs.clear();
	cout << "Case #" << ++c << ": ";
	while(N--){
		cin >> s;
		_r = part(s);
		pres.push_back(_r[0]);
		sufs.push_back(_r[_r.size() - 1]);
		for(int i = 1; i < _r.size() - 1; i++) parts[i].push_back(_r[i]);
	}
	string curPre = "", curSuf = "";
	for(string s : pres){
		if(s == "") continue;
		if(s.length() >= curPre.length()){
			if(s.substr(0, curPre.length()) != curPre){
				cout << "*" << endl;
				return;
			} else {
				curPre = s;
			}
		} else {
			if(curPre.substr(0, s.length()) != s){
				cout << "*" << endl;	
				return;
			}
		}
	}
	for(string s : sufs){
		if(s == "") continue;
		if(s.length() >= curSuf.length()){
			if(s.substr(s.length() - curSuf.length(), curSuf.length()) != curSuf){
				cout << "*" << endl;
				return;
			} else {
				curSuf = s;
			}
		} else {
			if(curSuf.substr(curSuf.length() - s.length(), s.length()) != s){
				cout << "*" << endl;	
				return;
			}
		}
	}
	cout << curPre;
	for(int i = 1; i <= 200; i++){
		for(string s : parts[i]) cout << s;
	}
	cout << curSuf << endl;
}


int main(){
	cin >> T;
	while(T--){
		solve();
	}
}

