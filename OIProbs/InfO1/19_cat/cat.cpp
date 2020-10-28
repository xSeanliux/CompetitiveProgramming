#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;
 
const int maxN = 3e6 + 326;
 
int N, arr[maxN], pos[maxN], T, posc, ansc;
pii ans[maxN];
bool vis[maxN];
 
inline void makeMove(int i, int j){
	swap(arr[i], arr[j]);
	swap(arr[N - i + 1], arr[N - j + 1]);
}
 
inline void disp(){
	for(int i = 1; i <= N; i++) cout << arr[i] << " \n"[i == N];
}
 
inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}
 
inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}
 
inline void solve(){
	Read(N);
	for(int i = 1; i <= N; i++) Read(arr[i]);
	for(int i = 1; i <= N / 2; i++) if(arr[i] + arr[N - i + 1] != N + 1){
		cout << -1 << endl;
		return;
	}
	posc = ansc = 0;
	for(int i = 1; i <= N / 2; i++) if(arr[i] > N / 2){
		if(arr[arr[i]] <= N / 2 && ((i + arr[i]) != (N + 1))){
			int nxt = arr[i], nn = arr[arr[i]];
			ans[ansc++] = {i, nxt};
			makeMove(i, nxt);
			//disp();
		}

	for(int i = 1; i <= N / 2; i++) if(arr[i] > N / 2){
		pos[posc++] = i;
	}
	if(posc & 1){ //not sure about this
		cout << -1 << endl;
		return;
	}
	/*
	cout << "have: ";
	for(int x : pos) cout << x << " ";
	cout << endl;
	*/
	for(int i = 0; i < posc; i += 2){
		makeMove(pos[i], N - pos[i + 1] + 1);	
		ans[ansc++] = {pos[i], N - pos[i + 1] + 1};
		//disp();
	}
	//disp();
	for(int i = 1; i <= N / 2; i++) assert(arr[i] <= N / 2);
	fill(vis, vis + N + 1, false);
	for(int i = 1; i <= N / 2; i++){
		while(i != arr[i]){
			int nxt = arr[i];
			makeMove(i, arr[i]);
			ans[ansc++] = {i, nxt};
			//disp();
		}
	}
	cout << ansc << " " << ansc << endl;
	for(int i = 0; i < ansc; i++) cout << ans[i].F << " " << ans[i].S << endl;
}
 
int main(){
	//ericxiao
	//
	Read(T);
	while(T--){
		solve();
	}
}
