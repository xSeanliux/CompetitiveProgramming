#include <iostream>
using namespace std;

const int maxN = 3e5 + 326;
char type[maxN];
int vals[maxN], N, ans[maxN], pos[maxN], bef[maxN], nxt[maxN];

int main(){
	cin >> N;
	for(int i = 0; i < 2 * N; i++){
		cin >> type[i];
		bef[i] = i - 1;
		nxt[i] = i + 1;
		if(type[i] == '-'){
			cin >> ans[i];
			pos[ans[i]] = i;
		}
	}
	for(int i = 1; i <= N; i++){
		if(bef[pos[i]] == -1 || type[bef[pos[i]]] == '-'){
			cout << "NO\n";
			return 0;
		}
		ans[bef[pos[i]]] = i;	
		int b = bef[bef[pos[i]]], n = nxt[pos[i]];
		if(b != -1) nxt[b] = n;
		bef[n] = b;
	}
	cout << "YES\n";
	for(int i = 0; i < 2 * N; i++){
		if(type[i] == '+'){
			cout << ans[i] << " ";
		}
	}
	cout << endl;
}

