#include <iostream>
#include <vector>
using namespace std;

const int maxN = 226;
int T, N, res[maxN], sam[maxN], dif[maxN], state[maxN];
int ans[maxN];
vector<int> alldiff, allsame, boths;

inline void solve(){
	fill(sa, sa + N / 10, -1);
	fill(dif, dif + N / 10, -1);
	alldiff.clear();
	allsame.clear();
	boths.clear();
	for(int i = 1; i <= N / 2; i++){
		cout << i << endl;
		cin >> res[i];
		cout << N - i << endl;
		cin >> res[N - i + 1];
		if(res[i] == res[N - i + 1]){
			sa[(i - 1) / 10 + 1] = i;
		} else {
			dif[(i - 1) / 10 + 1] = i;
		}
	}
	for(int i = 1; i <= N / 10; i++){
		if(dif[i] == -1) allsame.push_back(i);	
		else if(sam[i] == -1) alldif.push_back(i);
		else boths.push_back(i);
	}
	int cnt = 0;
	for(int ind : 
}
int main(){
	cin >> T;
	while(T--){
		cin >> N;
		solve();
	}
}
