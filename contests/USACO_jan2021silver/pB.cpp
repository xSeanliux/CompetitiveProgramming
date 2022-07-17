#include <iostream>
#include <string.h>
#include <stack>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;
int N, Q, pre[maxN], suf[maxN], l, r;
string s;
stack<char> stk; 

int main(){
	ericxiao
	cin >> N >> Q >> s;	
	pre[0] = 1;
	stk.push(s[0]);
	for(int i = 1; i < N; i++){
		while(stk.size() && stk.top() > s[i]) stk.pop();
		pre[i] = pre[i - 1] + !(stk.size() && s[i] == stk.top());
		stk.push(s[i]);
	}
	stk = stack<char>();
	suf[N - 1] = 1;
	stk.push(s[N - 1]);
	for(int i = N - 2; i >= 0; i--){
		while(stk.size() && stk.top() > s[i]) stk.pop();
		suf[i] = suf[i + 1] + !(stk.size() && s[i] == stk.top());
		stk.push(s[i]);
	}
	while(Q--){
		cin >> l >> r;
		int ans = 0;
		if(l > 1) ans += pre[l - 2];
		if(r < N) ans += suf[r];
		cout << ans << '\n';
	}
}
