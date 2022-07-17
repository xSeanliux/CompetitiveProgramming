#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string s, _r;
stack<char> stk;

string rem(string &a, int l, int r){ //removes [l, r] of s
	_r = "";
	for(int i = 0; i < a.length(); i++) if(i < l || i > r) _r += a[i];
	return _r;
}
int main(){
	ericxiao
	while(getline(cin, s)){
		string err = "er..."; 
		string _s = "";
		for(int i = 0; i < s.length(); i++){
			//cout << "i = " << i << endl;
			if(i + 4 < s.length()){
				bool found = false;
				for(int j = 0; j < 5; j++){
					if(s[i + j] != err[j]){
						//cout << "s[" << i + j << "] != " << err[j] << endl;
						break;
					} else if(j == 4) found = true;
				}
				//cout << "i = " << i << ", found = " << found << endl;
				if(found){
					//cout << "found at : " << i << endl;
					i += 4;
					continue;
				}
			}
			_s += s[i];
		}
		swap(_s, s);
		stk = stack<char>();
		for(char c : s){
			if(c != ' '){
				stk.push(c);
				continue;
			}
			if(!stk.size()) continue;
			if(stk.top() == ' ') continue;
			stk.push(c);
		}
		while(stk.size() && stk.top() == ' ') stk.pop();
		_s = "";
		while(stk.size()){
			_s += stk.top();
			stk.pop();
		}
		//cout << "removed err: s = " << s << endl;
		reverse(_s.begin(), _s.end());
		swap(_s, s);
		//cout << s <<endl;
		bool need = true;
		int cnt = 0;
		while(need && cnt++ < 300){
			for(int i = 0; i < s.length(); i++){
				if(s[i] == '$'){
					int l, r;
					for(l = i; l >= 0 && s[l] != '.'; l--);
					for(r = i; r < s.length() && s[r] != '.'; r++);
					if(l < 0) l = 0;
					if(s[l] == '.') l++;
					//cout << "l = " << l << ", r = " << r << endl;
					s = rem(s, l, r);
					//cout << "now " << s << endl;
					break;
				} else if(i == s.length() - 1){
					need = false;
				}
			}
		}
		//cout << "removed $: " << s << endl;
		stk = stack<char>();
		for(char c : s){
			if(c != ' '){
				stk.push(c);
				continue;
			}
			if(!stk.size()) continue;
			if(stk.top() == ' ') continue;
			stk.push(c);
		}
		while(stk.size() && stk.top() == ' ') stk.pop();
		_s = "";
		while(stk.size()){
			_s += stk.top();
			stk.pop();
		}
		reverse(_s.begin(), _s.end());
		swap(_s, s);
		cout << s << '\n';
	}
}
