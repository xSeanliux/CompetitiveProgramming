#pragma gcc optimize("Ofast")
#include <iostream>
#include <string.h>
#include <vector>
#include <bitset>
#include <cassert>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e3 + 326;

bitset<maxN> bs[maxN], arr[maxN];

int N, t;
vector<int> v, fail, emp;

string s;

inline bool ins(bitset<maxN> x){
	for(int i = N - 1; i >= 0; i--){
		if(!(x[i])) continue;
		if(!bs[i].none()) x ^= bs[i];
		else {
			bs[i] = x;
			return true;
		}
	}
	return false;
}

int main(){
	ericxiao
	cin >> N >> t;
	if(N == 1){
		string s;
		cin >> s;
		if(t == 1) cout << 0 << endl;
		else cout << s << endl;
		return 0;
	}
	for(int i = 0; i < N; i++){
		cin >> s;
		arr[i] = bitset<maxN>(s);
		if(!ins(arr[i])) fail.push_back(i);
	}
	for(int i = 0; i < N; i++) if(bs[i].none()) emp.push_back(i);
	assert(emp.size() == fail.size());
	if(t == 1){
		cout << emp.size() << endl;
		return 0;
	}
	for(int i = 0; i < fail.size(); i++){
		arr[fail[i]].flip(emp[i]);
	}
	for(int i = 0; i < N; i++){
		string s = arr[i].to_string();
		cout << s.substr(s.length() - N, N) << '\n';
	}
}
 
