#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
 
const int maxN = 526;
 
int T, N, M;
string s;
char mp[maxN][maxN];
int cnt;
 
struct DSU{
	int dsu[maxN * maxN];
	DSU(int N = 0, int M = 0){
		iota(dsu, dsu + N * M + 1, 0);	
	}
	void Flat(int x){
		if(x == dsu[x]) return;
		Flat(dsu[x]);
		dsu[x] = dsu[dsu[x]];
	}
	void Merge(int a, int b){
		Flat(a);
		Flat(b);
		dsu[dsu[a]] = dsu[b];	
	}
} dsu;
 
inline bool isValid(int i, int j){
	return i >= 0 && j >= 0 && i < N && j < M && mp[i][j] == 'X';
}
 
inline bool canPlace(int i, int j){
	if(i < 0 || j < 0 || i >= N || j >= M || mp[i][j] == 'X') return false;
	vector<int> tmp = vector<int>();
	if(isValid(i - 1, j)){
		dsu.Flat((i - 1) * M + j);
		tmp.push_back(dsu.dsu[(i - 1) * M + j]);
	}
	if(isValid(i, j + 1)){
		dsu.Flat((i) * M + j + 1);
		tmp.push_back(dsu.dsu[(i) * M + j + 1]);
	}
	if(isValid(i, j - 1)){
		dsu.Flat((i) * M + j - 1);
		tmp.push_back(dsu.dsu[(i) * M + j - 1]);
	}
	if(isValid(i, j + 1)){
		dsu.Flat((i) * M + j + 1);
		tmp.push_back(dsu.dsu[(i) * M + j + 1]);
	}
	sort(tmp.begin(), tmp.end());
	for(int i = 1; i < tmp.size(); i++) if(tmp[i - 1] == tmp[i]) return false;
	return true;
}
 
inline bool isTouching(int i, int j){
	dsu.Flat(0);
	dsu.Flat(i * M + j);
	return dsu.dsu[0] == dsu.dsu[i * M + j];
}
 
inline void place(int i, int j){
	if(isValid(i - 1, j)){
		dsu.Merge(i * M + j, (i - 1) * M + j);
	}
	if(isValid(i, j + 1)){
		dsu.Merge(i * M + j, (i) * M + j + 1);
	}
	if(isValid(i, j - 1)){
		dsu.Merge(i * M + j, (i) * M + j - 1);
	}
	if(isValid(i, j + 1)){
		dsu.Merge(i * M + j, (i) * M + j + 1);
	}
}
 
inline void solve(){
	cin >> N >> M;
	dsu = DSU(N, M);
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < M; j++) mp[i][j] = s[j];
	}
	if(N == 1){
		for(int i = 0; i < M; i++) cout << 'X';
		cout << endl;
		return;
	}
	if(M % 3 == 0){
		for(int j = 1; j < M; j += 3){
			for(int i = 0; i < N; i++) mp[i][j] = 'X';
			if(j + 2 < M){
				if(mp[1][j + 1] == 'X' || mp[1][j + 2] == 'X'){
					mp[1][j + 1] = 'X';
					mp[1][j + 2] = 'X';
				} else {
					mp[0][j + 1] = 'X';
					mp[0][j + 2] = 'X';
				}
			}
		}
	} else if(M % 3 == 1){
		for(int j = 0; j < M; j += 3){
			for(int i = 0; i < N; i++) mp[i][j] = 'X';
			if(j + 2 < M){
				if(mp[1][j + 1] == 'X' || mp[1][j + 2] == 'X'){
					mp[1][j + 1] = 'X';
					mp[1][j + 2] = 'X';
				} else {
					mp[0][j + 1] = 'X';
					mp[0][j + 2] = 'X';
				}
			}
		}	
	} else {
		for(int j = 1; j < M; j += 3){
			for(int i = 0; i < N; i++) mp[i][j] = 'X';
			if(j + 2 < M){
				if(mp[1][j + 1] == 'X' || mp[1][j + 2] == 'X'){
					mp[1][j + 1] = 'X';
					mp[1][j + 2] = 'X';
				} else {
					mp[0][j + 1] = 'X';
					mp[0][j + 2] = 'X';
				}
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++) cout << mp[i][j];
		cout << endl;
	}
}
int main(){
	cin >> T;
	while(T--){
		cnt++;
		solve();
	}
}
