#include <iostream>
#include <stack>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 5e5 + 10, maxLog = 20;
int to[maxN], N, Q, type[maxN], loopid[maxN], cnt = 1, loopsz[maxN], jump[maxLog][maxN];
int stk[maxN], m = 0, him, her;
bool visited[maxN];

pii better(pii a, pii b){
	if(max(a.F, a.S) != max(b.F, b.S)){
		return max(a.F, a.S) < max(b.F, b.S) ? a : b;
	}
	if(min(a.F, a.S) != min(b.F, b.S)){
		return min(a.F, a.S) < min(b.F, b.S) ? a : b;
	}
	return a.F >= a.S ? a : b;
}

void dfs(int u){
	visited[u] = true;
	stk[m++] = u;
	if(visited[to[u]]){
		if(type[to[u]] && loopid[to[u]] == -maxN){
			while(m){
				type[stk[--m]] = type[to[u]];
			}
			return;
		} else {
			if(!type[to[u]]){
				int id = 0;
				while(m){
					type[stk[--m]] = cnt;
					id++;
					loopid[stk[m]] = -id;
					if(stk[m] == to[u]) break;
				}
				loopsz[cnt] = id;
				cnt++;
			}
			if(!m) return;
			while(m){
				type[stk[--m]] = cnt;
			}
			cnt++;
		}
		return;
	}
	dfs(to[u]);
}

inline int dep(int x){
	int d = 0;
	for(int i = maxLog - 1; i >= 0; i--){
		if(type[jump[i][x]] == type[x]){
			d += (1 << i);
			x = jump[i][x];
		}
	}
	return d + 1;
}

inline int getRoot(int x){
	for(int i = maxLog - 1; i >= 0; i--){
		if(type[x] == type[jump[i][x]]) x = jump[i][x];
	}
	return to[x];
}

inline int sub(int a, int b, int m){
	return a - b < 0 ? a - b + m : a - b; 
}
int main(){
	ericxiao;
	cin >> N >> Q;	
	for(int i = 1; i <= N; i++) cin >> to[i];
	fill(loopid, loopid + 1 + N, -maxN);
	for(int i = 1; i <= N; i++){
		if(!visited[i]){
			m = 0;
			dfs(i);
		}
	}
	
	for(int i = 1; i <= N; i++){
		jump[0][i] = to[i];
		loopid[i] += loopsz[type[i]];
	}
	/*
	for(int i = 1; i <= N; i++){
		cout << "type[" << i << "] = " << type[i] << endl;
		cout << "loopid = " << loopid[i] << endl;
		cout << endl;
	}
	*/
	for(int i = 1; i < maxLog; i++){
		for(int j = 1; j <= N; j++){
			jump[i][j] = jump[i - 1][ jump[i - 1][j] ];	
		}
	}
	while(Q--){
		cin >> him >> her;
		if(type[jump[maxLog - 1][him]] != type[jump[maxLog - 1][her]]){
			cout << "-1 -1" << endl;
			continue;
		}
		if(!loopsz[type[him]]){ //him is tree
			if(!loopsz[type[her]]){ //her is tree
				if(type[him] == type[her]){ //same tree
					int a = 0, b = 0;
					int dhim = dep(him), dher = dep(her);
					//cout << "dhim = " << dhim << ", dher = " << dher << endl;
					if(dhim > dher){
						for(int i = 0; i < maxLog; i++){
							if(((dhim - dher) >> i) & 1) {
								him = jump[i][him];
								a += (1 << i);
							}
						}
					} 
					if(dher > dhim){
						for(int i = 0; i < maxLog; i++){
							if(((dher - dhim) >> i) & 1){
								her = jump[i][her];
								b += (1 << i);
							}
						}
					}
					//cout << "him = " << him << ", her = " << her << endl;
					if(him == her){
						cout << a << " " << b << endl;
						continue;
					}
					for(int i = maxLog - 1; i >= 0; i--){
						if(jump[i][him] != jump[i][her]){
							him = jump[i][him];
							her = jump[i][him];
							a += (1 << i);
							b += (1 << i);
						}
					}
					cout << a + 1 << " " << b + 1 << endl;
				} else { //different trees
					int a = dep(him), b = dep(her);
					him = getRoot(him);
					her = getRoot(her);
					pii sol1 = {a + sub(loopid[her], loopid[him], loopsz[type[him]]) , b};
					pii sol2 = {a, b + sub(loopid[him], loopid[her], loopsz[type[him]])};
					pii sol = better(sol1, sol2);
					cout << sol.F << " " << sol.S << endl;
				}
			} else { //her is loop
				int a = dep(him), b = 0;
				him = getRoot(him);
				pii sol1 = {a + sub(loopid[her], loopid[him], loopsz[type[him]]) , 0};
				pii sol2 = {a, sub(loopid[him], loopid[her], loopsz[type[him]])};
				pii sol = better(sol1, sol2);
				cout << sol.F << " " << sol.S << endl;
			}
		} else {
			if(!loopsz[type[her]]){ //her is tree
				int b = dep(her);
				her = getRoot(her);
				pii sol1 = {sub(loopid[her], loopid[him], loopsz[type[him]]) , b};
				pii sol2 = {0, b + sub(loopid[him], loopid[her], loopsz[type[him]])};
				pii sol = better(sol1, sol2);
				cout << sol.F << " " << sol.S << endl;
			} else {
				pii sol1 = {sub(loopid[her], loopid[him], loopsz[type[him]]) , 0};
				pii sol2 = {0, sub(loopid[him], loopid[her], loopsz[type[him]])};
				pii sol = better(sol1, sol2);
				cout << sol.F << " " << sol.S << endl;
			}
		}
	}
}
