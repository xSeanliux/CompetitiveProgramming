#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int maxN = 2260;
vector<int> ans, _ans;
queue<int> places[maxN];
int T, N, arr[maxN], tmp[maxN], perm[maxN], place[maxN];
bool visited[maxN];

inline void solve(){
	cin >> N;
	set<int> st;
	vector<int>().swap(ans);
	vector<int>().swap(_ans);
	for(int i = 0; i <= N; i++){
		places[i] = queue<int>();
		visited[i] = false;
	}
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		perm[i] = i;
		places[arr[i]].push(i);
		st.insert(i);
	}
	int mexcnt = 0;
	while(mexcnt < N && places[mexcnt].size()) mexcnt++;
	for(int i = 0; i <= N; i++){
		while(places[i].size() > 1){
			int k = places[i].front();
			places[i].pop();
			arr[k] = mexcnt;
			ans.push_back(k);
			places[mexcnt].push(k);
			while(mexcnt < N && places[mexcnt].size()) mexcnt++;
		}
	}
	while(places[N].size()){
		int k = places[N].front();
		places[N].pop();
		arr[k] = mexcnt;
		ans.push_back(k);
		places[mexcnt].push(k);
		while(mexcnt < N && places[mexcnt].size()) mexcnt++;
	}
	//cout << "perm: " << endl;
	//for(int i = 0; i < N; i++) cout << arr[i] << " \n"[i == N - 1];
	bool isSolved = false;
	for(int i = 0; i < N; i++) if(arr[i] == i) visited[i] = true;
	while(true){
		int st;
		for(st = N - 1; st >= 0; st--){
			if(!visited[st]) break;
			if(!st){
				isSolved = true;
				break;
			}
		}
		if(isSolved) break;
		ans.push_back(st);
		int curmex = arr[st];
		arr[st] = N;
		visited[st] = true;
		while(arr[curmex] != N){
			ans.push_back(curmex);
			visited[curmex] = true;
			swap(arr[curmex], curmex);
		}
		//for(int i = 0; i < N; i++) cout << arr[i] << " ";
		//cout << endl;
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x + 1 << " ";
	cout << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
