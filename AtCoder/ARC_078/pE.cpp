#include <iostream>
#include <string.h>
#include <algorithm>
#include <cassert>
#define int long long int
using namespace std;

int N, cnt;
char c;

bool Query(int x){
	assert(cnt < 64 && x <= 1e18 && x > 0);
	cnt++;
	cout << "? " << x << endl;
	//cout << ((x <= N && to_string(x) <= to_string(N)) || (x > N && to_string(x) > to_string(N))) << endl; 
	return (x <= N && to_string(x) <= to_string(N)) || (x > N && to_string(x) > to_string(N));
}

signed main(){
	//cin >> N;
	int curAns = 0;
	for(int i = 0; i < 10; i++){
		int l = (i == 0), r = 10, x;
		while(r - l > 1){
			x = (l + r) / 2;
			Query(curAns * 10 + x);
			cin >> c;
			if(c == 'Y'){
				l = x;
			} else {
				r = x;
			}
		}
		curAns = curAns * 10 + l;
	}
	string A = to_string(curAns), pre;
	for(int i = A.length() - 1; i; i--){
		char c = A[i];
		A[i] = '0';
		Query(stoll(A));
		A[i] = c;
		cin >> c;
		if(c == 'N'){
			pre = A.substr(0, i);
			break;
		}
	}
	for(int i = 0; i < 10; i++){
		if(pre == "" && !i) continue;
		string B = pre + (char)(i + '0') + "0000000";
		Query(stoll(B));
		cin >> c;
		if(c == 'Y'){
			A = pre + (char)(i + '0');
			break;
		}
	}
	/*
	int l = (pre == ""), r = 10, x;
	while(r - l > 1){
		x = (l + r) / 2;
		string B = pre + (char)(x + '0') + "00000000";
	}
	*/
	//cout << "All nonzero: " << A << endl;
	if(A.length() == 1 && A[0] == '1'){
		string jizz = "";
		for(int i = 1;; i++){
			jizz += '9';
			Query(stoll(jizz));
			cin >> c;
			if(c == 'Y'){
				string ans = "1";
				while(ans.length() < jizz.length()) ans += '0';
				cout << "! " << ans << endl;
				return 0;
			}
		}
	}
	string x = to_string(stoll(A) - 1);
	while(true){
		x += '0';	
		Query(stoll(x));
		cin >> c;
		if(c == 'N'){
			break;
		}
	}
	while(A.length() < x.length() - 1) A += '0';
	cout << "! " << A << endl;
}
