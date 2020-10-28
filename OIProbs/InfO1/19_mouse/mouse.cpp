#include <iostream>
#include <vector>
#include "grader.h"
using namespace std;

const int maxN = 326;
int ans[maxN], ANS[maxN], N;
bool has[maxN], found;

/*
int query(vector<int> q){
	int ans = 0;
	cout << "Asking: ";
	for(int i = 0; i < N; i++){
		cout << q[i] << " ";
		ans += (q[i] == ANS[i]);
	}
	cout << ": " << ans << endl;
	return ans;
}
*/

bool dfs(int now, int N){
	if(found) return true;
	vector<int> q;
	vector<int>().swap(q);
	if(now == N){
		for(int i = 0; i < N; i++) q.push_back(ans[i]);
		if(query(q) == N){
			found = true;
			return true;
		}
		return false;
	}
	for(int j = 0; j < now; j++){
		//cout << "ans[" << j << "] = " << ans[j] << endl;
		q.push_back(ans[j]); 
	}
	for(int j = 1; j <= N; j++) if(!has[j]){
		q.push_back(j);
	}
	if(found) return true;
	int baseline = query(q);
	if(baseline == N) return true;
	vector<int> asked;
	asked.clear();
	asked.push_back(now);
	for(int j = now + 1; j < N; j++){
		swap(q[j], q[now]);
		if(found) return true;
		int res = query(q);
		if(res == N) return true;
		if(res > baseline){
			asked.clear();
			asked.push_back(j);
			baseline = res;
		} else if(res == baseline){
			asked.push_back(j);
		}
		swap(q[j], q[now]);
	}
	for(int x : asked){
		///cout << "x = " << x << endl;
		has[q[x]] = true;
		ans[now] = q[x];
		if(dfs(now + 1, N)) {
			//cout << "ans[" << now << "] = " << q[x] << endl; 
			return true;
		}
		has[q[x]] = false;
	}
	return false;
}

void solve(int N){
	dfs(0, N);
}

/*
int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> ANS[i];
	solve(N);
}
*/

