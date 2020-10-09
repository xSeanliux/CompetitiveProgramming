#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int INF = 3e18;

vector<int> a, b;
vector<pii> ans[3];
map<int, pii> sib;
map<int, int> ib;

int N, M, sa, sb, a0 = INF, a1 = INF, a2 = INF;

inline int Abs(int x){
	return x < 0 ? -x : x;
}

signed main(){
	ericxiao;
	cin >> N;
	a.resize(N);
	ans[1].resize(1);
	ans[2].resize(2);
	for(int i = 0; i < N; i++){
		cin >> a[i];
		sa += a[i];
	}
	cin >> M;
	b.resize(M);
	for(int i = 0; i < M; i++){
		cin >> b[i];
		sb += b[i];
		ib[b[i]] = i + 1;
	}
	
	for(int i = 0; i < M; i++){
		for(int j = i + 1; j < M; j++){
			sib[b[i] + b[j]] = {i + 1, j + 1};
		}
	}

	a0 = Abs(sa - sb);
	int tgt = (sa - sb) / 2, delta;
	//cout << "looking at one swap: " << endl;
	for(int i = 0; i < N; i++){
		int sum = a[i];
		//cout << "s = " << sum << endl;
		auto it = ib.lower_bound(sum - tgt);
		if(it == ib.end()) --it;
		delta = (sum - it->F);
		if(a1 > Abs(sa - sb - 2 * delta)){
			a1 = Abs(sa - sb - 2 * delta);
			ans[1][0] = {i + 1, it->S};
		}
		if(it != ib.begin()){
			--it;
			delta = (sum - it->F);
			if(a1 > Abs(sa - sb - 2 * delta)){
				a1 = Abs(sa - sb - 2 * delta);
				ans[1][0] = {i + 1, it->S};
			}
		}
	}
	if(N > 1 && M > 1){
		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N; j++){
				pii p = {i + 1, j + 1};
				int sum = a[i] + a[j];
				auto it = sib.lower_bound(sum - tgt);
				if(it == sib.end()) --it;
				delta = (sum - it->F);
				if(a2 > Abs(sa - sb - 2 * delta)){
					a2 = Abs(sa - sb - 2 * delta);
					ans[2][0] = {p.F, it->S.F};
					ans[2][1] = {p.S, it->S.S};
				}
				if(it != sib.begin()){
					--it;
					delta = (sum - it->F);
					if(a2 > Abs(sa - sb - 2 * delta)){
						a2 = Abs(sa - sb - 2 * delta);
						ans[2][0] = {p.F, it->S.F};
						ans[2][1] = {p.S, it->S.S};
					}
				}
			}
		}
	}
	if(a0 <= a1 && a0 <= a2){
		cout << a0 << endl << 0 << endl;
		return 0;
	}
	if(a1 <= a0 && a1 <= a2){
		cout << a1 << endl;
		cout << 1 << endl;
		cout << ans[1][0].F << " " << ans[1][0].S << endl;
		return 0;
	}
	cout << a2 << endl;
	cout << 2 << endl;
	cout << ans[2][0].F << " " << ans[2][0].S << endl;
	cout << ans[2][1].F << " " << ans[2][1].S << endl;

}
