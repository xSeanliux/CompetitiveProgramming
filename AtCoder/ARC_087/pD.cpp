#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 1.6e4 + 326;
bool dir = 0;
string s;
int x, y;

struct Backpack{
	int dp[maxN], ndp[maxN];
	Backpack(int st = 0){
		fill(dp, dp + maxN, 0);
		dp[8000 + st] = 1;
	}
	void add(int x){
		for(int i = 0; i < maxN; i++){
			ndp[i] = 0;
			if(i >= x) ndp[i] |= dp[i - x];
			if(i + x < maxN) ndp[i] |= dp[i + x];
		}
		for(int i = 0; i < maxN; i++) dp[i] = ndp[i];
	}
} go[2];

int main(){
	cin >> s >> x >> y;	
	int cnt = 0;
	x += 8000;
	y += 8000;
	bool f = true;
	for(char c : s){
		if(c == 'F') cnt++;
		else {
			if(f){
				go[dir] = Backpack(cnt);
				cnt = 0;
				dir ^= 1;
				f = false;
				continue;
			}
			go[dir].add(cnt);
			dir ^= 1;
			cnt = 0;
		}
	}
	if(f){
		go[dir] = Backpack(cnt);
	} else {
		go[dir].add(cnt);
	}
	if(go[0].dp[x] && go[1].dp[y]) cout << "Yes\n";
	else cout << "No\n";
}
