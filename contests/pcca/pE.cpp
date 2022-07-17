#include <iostream>
#include <vector>
using namespace std;

const int maxN = 326;
int N, K, arr[maxN], has[maxN];

bool dfs(int now = 0, int tgt = N, int curm = 0){
	//cout << "now at " << now << ", " << tgt << ", " << curm << endl;
	if(now == K){
		if(tgt) return false;
		//for(int i = 0; i < K; i++){
		//	cout << arr[i] << " ";
		//}
		//cout << endl;
		fill(has, has + N + 1, 0);
		for(int i = 0; i < (1 << (K - 1)); i++){
			int a = 0, b = 0;
			for(int j = 0; j < K; j++) if((i >> j) & 1){
				a += arr[j];
			} else b += arr[j];
			if(has[a] || has[b]) return false;
			has[a] = true;
			has[b] = true;
		}
		return true;
	}
	for(int i = curm + 1; i <= tgt; i++){
		//cout << "putting in " << i << endl;
		//i + (i + 1) + ... + (i + K - 1 - now) <= tgt
		//=> (i + i + K - 1) * (K - now) / 2 <= tgt
		arr[now] = i;
		if(dfs(now + 1, tgt - i, i)) return true;
	}
	return false;
}

int main(){
	cin >> N >> K;	
	if(K * (K + 1) / 2 > N || K > 7 || (1 << K) > N + 1){
		cout << "No\n";
		return 0;
	}
	if(dfs()){
		cout << "Yes\n";
		for(int i = 0; i < K; i++) cout << arr[i] << " \n"[i == K - 1];
	} else {
		cout << "No\n";
	}
}
