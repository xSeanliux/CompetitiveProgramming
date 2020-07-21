#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int maxN = 50 + 26;
int t, n, m;
string s;
bool canGo[maxN][maxN], visited[maxN][maxN];
char mp[maxN][maxN];
queue<int> que;

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
		visited[i][j] = false;
		canGo[i][j] = true;
	}
	int gc = 0;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 1; j <= m; j++){
			mp[i][j] = s[j - 1];
			if(mp[i][j] == 'B'){
				canGo[i + 1][j] = canGo[i - 1][j] = canGo[i][j + 1] = canGo[i][j - 1] = false;	
			}
			if(mp[i][j] == '#') canGo[i][j] = false;
			gc += (mp[i][j] == 'G');
		}
	}
	if(!gc){
		cout << "Yes\n";
		return;
	}
	if(!canGo[n][m]){
		cout << "No\n";
		return;
	}
	que = queue<int>();
	que.push(n * maxN + m);
	visited[n][m] = true;
	while(que.size()){
		int f = que.front();
		int y = f / maxN, x = f % maxN;
		que.pop();
		if(!visited[y - 1][x] && canGo[y - 1][x]){
			visited[y - 1][x] = true;
			que.push((y - 1) * maxN + x);
		}
		if(!visited[y + 1][x] && canGo[y + 1][x]){
			visited[y + 1][x] = true;
			que.push((y + 1) * maxN + x);
		}
		if(!visited[y][x + 1] && canGo[y][x + 1]){
			visited[y][x + 1] = true;
			que.push((y) * maxN + x + 1);
		}
		if(!visited[y][x - 1] && canGo[y][x - 1]){
			visited[y][x - 1] = true;
			que.push((y) * maxN + x - 1);
		}
	}
	bool can = true;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mp[i][j] == 'G'){
				can &= (visited[i][j] && canGo[i][j]);		
			}
		}
	}
	cout << (can ? "Yes\n" : "No\n");
}
int main(){
	cin >> t;
	while(t--){
		solve();
	}
}
