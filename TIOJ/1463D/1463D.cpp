#include <iostream>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 326;
vector<int> S, B, a, b;

bool isIn[2 * maxN];

inline bool cover(vector<int> &a, vector<int> &b){
	for(int i = 0; i < a.size(); i++) if(a[i] <= b[i]) return false;
	return true;
}


int T, N, x;

inline void solve(){
	cin >> N;
	vector<int>().swap(S);
	vector<int>().swap(B);
	fill(isIn, isIn + 2 * N + 1, false);
	for(int i = 0; i < N; i++){
		cin >> x;
		isIn[x] = true;
	}
	for(int i = 1; i <= 2 * N; i++) (isIn[i] ? B : S).push_back(i);
	int limA, limB;
	int l, r, m;
	l = 0, r = N + 1;
	while(l + 1 < r){
		m = (l + r) / 2;
		vector<int>().swap(a);
		vector<int>().swap(b);
		for(int i = 0; i < m; i++){
			a.push_back(B[i]);
			b.push_back(S[N - m + i]);
		}
		if(cover(b, a)) l = m;
		else r = m;
	}
	limA = l;
	l = 0, r = N + 1;
	while(l + 1 < r){
		m = (l + r) / 2;
		vector<int>().swap(a);
		vector<int>().swap(b);
		for(int i = 0; i < m; i++){
			a.push_back(S[i]);
			b.push_back(B[N - m + i]);
		}
		if(cover(b, a)) l = m;
		else r = m;
	}
	limB = l;
	int ans = 0;
	for(int i = 0; i <= limA; i++){
		ans += ((N - i) <= limB);
	}
	cout << ans << endl;
}

int main(){
	ericxiao
	cin >> T;
	while(T--){
		solve();
	}
}

