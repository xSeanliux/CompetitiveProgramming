#include <iostream>
using namespace std;

const int maxN = 5e5 + 26;
int N, arr[maxN], has[maxN], visited[maxN], ans;

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		has[arr[i]]++;
		if(i == arr[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= N; i++){
		if(has[i] != 1){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= N; i++){
		if(visited[i]) continue;
		ans++;
		int x = i;
		while(!visited[x]){
			visited[x] = true;	
			x = arr[x];
		}
	}
	cout << ans << endl;
}
