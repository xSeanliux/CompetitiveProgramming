#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 1e3 + 226;
int n, k, t, s, x, res;
vector<int> sets[maxN], cur, nxt, tmp;
bool has[maxN];
string jizz;

void solve(){
	cin >> n >> k;	
	for(int i = 0; i < k; i++){
		cin >> s;
		sets[i].resize(s);
		for(int j = 0; j < s; j++){
			cin >> sets[i][j];
		}
		sort(sets[i].begin(), sets[i].end());
	}
	int mx;
	cout << "? " << n;
	for(int i = 1; i <= n; i++) cout << " " << i;
	cout << endl;
	cin >> mx;
	int l = 1, r = n + 1, m;
	while(l + 1 < r){
		m = (l + r) / 2;	
		cout << "? " << (m - l);
		for(int i = l; i < m; i++) cout << " " << i;
		cout << endl;
		cin >> res;
		if(res == mx) r = m;
		else l = m;
	}
	//cout << "Done! max is " << l << endl;
	int sec;
	for(int i = 0; i < k; i++){
		if(lower_bound(sets[i].begin(), sets[i].end(), l) != sets[i].end() && *lower_bound(sets[i].begin(), sets[i].end(), l) == l){
			fill(has, has + n + 1, false);
			for(int x : sets[i]){
				has[x] = true;
			}
			cout << "? " << n - sets[i].size();
			for(int j = 1; j <= n; j++) if(!has[j]) cout << " " << j;
			cout << endl;
			cin >> sec;
		}
	}
	cout << "!";
	for(int i = 0; i < k; i++){
		if(lower_bound(sets[i].begin(), sets[i].end(), l) != sets[i].end() && *lower_bound(sets[i].begin(), sets[i].end(), l) == l){
			cout << " " << sec;
		} else {
			cout << " " << mx;
		}
	}
	cout << endl;
	cin >> jizz; // read a string ...
}

int main(){
	cin >> t;
	while(t--){
		solve();	
	}
}
