#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int maxN = 226;  
int T, N, dist[maxN][maxN], c;
string I, O;
vector<int> adj[maxN];

inline void solve(){
	cin >> N >> I >> O;
	for(int i = 0; i < N; i++){
		vector<int>().swap(adj[i]);
		for(int j = 0; j < N; j++){
			dist[i][j] = maxN;
		}
		dist[i][i] = 0;
	}
	for(int i = 0; i < N; i++){
		if(i){
			if(I[i - 1] == 'Y' && O[i] == 'Y'){
				adj[i].push_back(i - 1);
				dist[i][i - 1] = 0;
			}
		} if(i < N - 1){
			if(I[i + 1] == 'Y' && O[i] == 'Y'){
				adj[i].push_back(i + 1);
				dist[i][i + 1] = 0;
			}
		}
	}
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	cout << "Case #" << ++c << ":" << endl;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << (dist[i][j] == 0 ? 'Y' : 'N');
		}
		cout << endl;
	}
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
