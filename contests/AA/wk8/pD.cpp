#include <iostream>
using namespace std;

const int maxN = 20;
int N, B, arr[maxN], ans;

void dfs(int now, int a, int b, int c){
	if(now == N){
		if(a + b + c > 2 * max(a, max(b, c))) ans++;
		return;
	}
	dfs(now + 1, a + arr[now], b, c);
	dfs(now + 1, a, b + arr[now], c);
	dfs(now + 1, a, b, c + arr[now]);
}

int main(){
	cin >> N >> B;
	for(int i = 0; i < N; i++) cin >> arr[i];
	for(int i = 0; i < 
	dfs(0, B, B, B);
	cout << ans;
}
