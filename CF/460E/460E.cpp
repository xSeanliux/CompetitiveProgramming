#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

int N, R, x, y, choice[26], optchoice[26], ans, lim;
const double PI = acos(-1);
vector<pii> cand[26];

int hyp(int a, int b){
	return a * a + b * b;
}

void dfs(int now = 1){
	if(now == N){
		int s = 0;
		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N; j++){
				s += hyp(cand[i][choice[i]].F - cand[j][choice[j]].F, cand[i][choice[i]].S - cand[j][choice[j]].S);
			}
		}
		if(s > ans){
			ans = s;
			for(int i = 0; i < N; i++) optchoice[i] = choice[i];
		}
		return;
	}
	for(int i = 0; i < cand[now].size(); i++){
		choice[now] = i;
		dfs(now + 1);
	}
}

int main(){
	cin >> N >> R;
	if(N == 1){
		cout << "0\n0 0\n";
		return;
	}
	if(N == 2){
		cout << R * R * 4 << endl << R << " " << 0 << endl << 0 << " " << R << endl;
	}
	cand[0] = {{R, 0}};
	if(N == 3){
		
	}
	if(N == 4){
		int ans = 0;
		cand[0] = {
			{R , 0},
			{-R, 0},
			{0 , R},
			{0, -R}
		};
		for(int i = 0; i < 4; i++){
			for(int j = i + 1; j < 4; j++){
				ans += hyp(cand[0][i], cand[0][j]);
			}
		}
		cout << ans << endl;
		for (auto [x, y] : cand[0]){
			cout << x << " " << y << endl;
		}
	}
	if(N == 5){
		cand[0].clear();
		for(int i = 1; i < N; i++){
			x = 
		}
	}
	if(N == 6){

	} 
	if(N == 7){
		
	}
	if(N == 8){
		for(int i = 0; i; i++){
			if(hypot(i +
		}
	}
}
