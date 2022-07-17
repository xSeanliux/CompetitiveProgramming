#include <iostream>
using namespace std;

const int maxN = 16;

bool vis[1 << maxN], f;
int ord[1 << maxN], N;

void toStr(int x){
	for(int i = 0; i < N; i++) cout << ((ord[x] >> i) & 1);
	cout << endl;
}
void dfs(int now = 0, int cnt = 1){
	if(cnt == (1 << N)){
		f = true;
		for(int i = 0; i < (1 << N); i++) toStr(i);
		return;
	}
	if(f) return;
	for(int i = 0; i < N; i++){
		if(!vis[(now) ^ (1 << i)]){
			vis[(now) ^ (1 << i)] = true;
			ord[cnt] = (now) ^ (1 << i);
			dfs((now) ^ (1 << i), cnt + 1);
			vis[(now) ^ (1 << i)] = false;
		}
	}
}



int main(){
	cin >> N;
	vis[0] = true;
	dfs();
}
