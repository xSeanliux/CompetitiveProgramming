#include <iostream>
#include <utility>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
int N, M, cnt[maxN], ans[maxN], cur = -1, amnt = 0;
set<pii> st;

inline void add(int x){
	if(cur == -1){
		cur = x;
		amnt = 1;
		return;
	}
	if(cur == x) amnt++;
	else amnt--;
	if(!amnt) cur = -1;
}

int main(){
	cin >> N >> M;
	int sz = 0;
	for(int i = 1; i <= M; i++){
		cin >> cnt[i];
		if(i > 1){
			st.push({cnt[i], i});
			sz += i;
	}
	auto [n, x] = *st.rbegin();
	if(n > 2 * N && x != 1){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int curAt = 2;
	while(st.size()){

	}
}
