#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 10;
deque<int> dq, pos[maxN];
set<pii> st;
vector<int> vec;
int T, N, x, y, g[maxN], ans[maxN];

inline void solve(){
	cin >> N >> x >> y;
	dq = deque<int>();
	st = set<pii>();
	vector<int>().swap(vec);
	for(int i = 0; i <= N + 1; i++) pos[i] = deque<int>();
	for(int i = 1; i <= N; i++){
		cin >> g[i];
		ans[i] = -1;
		pos[g[i]].push_back(i);
	}
	int filler = -1; 
	for(int i = 1; i <= N + 1; i++){
		if(!pos[i].size()) filler = i;
		if(pos[i].size()) st.insert({pos[i].size(), i});
	}
	int z = x;
	while(z--){
		auto [sz, val] = *st.rbegin();
		st.erase(--st.end());
		ans[pos[val].front()] = val;
		pos[val].pop_front();
		if(pos[val].size()) st.insert({pos[val].size(), val});
		y--;
	}
	for(auto [sz, val] : st){
		for(int p : pos[val]) vec.push_back(p);
	}
	for(int i = 0; y && i < vec.size(); i++){
		if(g[vec[i]] != g[vec[(i + vec.size() / 2) % vec.size()]]){
			ans[vec[i]] = g[vec[(i + vec.size() / 2) % vec.size()]];
			y--;	
		}
	}
	if(y){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 1; i <= N; i++){
		cout << (ans[i] == -1 ? filler : ans[i]) << " \n"[i == N];
	}
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
