#include <iostream>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

vector<pii> vec;

const int maxN = 2e5 + 326;
int T, N, hei[maxN];

inline void solve(){
	cin >> N;
	vector<pii>().swap(vec);
	pii cur = {0, 0};
	for(int i = 0; i < N; i++){
		cin >> hei[i];	
		if(!i) cur = {hei[i], hei[i]};
		else {
			if(hei[i] >= hei[i - 1]) cur.S = hei[i];
			else {
				vec.push_back(cur);
				cur = {hei[i], hei[i]};
			}
		}
	}
	vec.push_back(cur);
	long long int ans = 0;
	for(int i = vec.size() - 1; i > 0; i--){
		if(vec[i].F >= vec[i - 1].S) continue;
		ans += vec[i - 1].S - vec[i].F;
		vec[i].S = max(vec[i].S, vec[i - 1].S);
	}
	cout << ans << endl;
}
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
