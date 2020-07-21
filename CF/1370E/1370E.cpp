#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <vector>
#define F first
#define S second
#define pii pair<int,int>
using namespace std;
 
const int maxN = 1e6 + 10;
 
int N, cnt;
bool cur = false;
vector<int> things;
string s, t, a, b;
 
 
int st, en; 
 

int main(){
	cin >> N >> s >> t;	
	for(int i = 0; i < N; i++){
		if(s[i] == t[i]) continue;	
		if(s[i] - '0' == cur) cnt++;
		else {
			if(cnt) things.push_back(cnt);
			cur ^= 1;
			cnt = 1;
		}
	}
	if(cnt) things.push_back(cnt);
	if(!things.size()){
		cout << 0 << endl;
		return 0;
	}
	cnt = 0;
	for(int i = 0; i < things.size(); i++) cnt += (i & 1 ? 1 : -1) * things[i];
	if(cnt){
		cout << -1 << endl;
		return 0;
	}
	if(things.size() % 2){
		things[0] += things[things.size() - 1];
		things.pop_back();
	}
	vector<pii> now, nxt;
	for(int i = 0; i < things.size(); i++){
		now.emplace_back(things[i], i & 1);
	}
	int ans = 0;
	while(now.size()){ //how is this correct lol
		int mn = N;
		for(auto [a, b] : now) mn = min(mn, a);
		ans += mn;
		vector<pii>().swap(nxt);
		for(auto [a, b] : now){
			if(a == mn) continue;
			if(!nxt.size()){
				nxt.emplace_back(a - mn, b);
				continue;
			}
			if(b == nxt[nxt.size() - 1].S){
				nxt[nxt.size() - 1].F += a - mn;
			} else {
				nxt.emplace_back(a - mn, b);
			}
		}
		swap(now, nxt);
	}
	cout << ans << endl;
}
 
