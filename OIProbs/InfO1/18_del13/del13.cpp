#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

const int maxN = 18;
int T, N, M, l2[1 << maxN], fromst[1 << maxN], del[1 << maxN];
bool pos[1 << maxN];
bool has[100000];

void solve(){
	cin >> M;
	vector<int> has, wok;
	has.resize(M);
	fill(pos, pos + (1 << N), false);
	for(int i = 0; i < M; i++){
		cin >> has[i];
		has[i]--;
	}
	queue<int> que;
	que.push((1 << N) - 1);
	pos[(1 << N) - 1] = true;
	int curst = 0;
	for(int x : has) curst ^= (1 << x);
	bool f = false;
	while(que.size()){
		if(f) break;
		int i = que.front();
		que.pop();
		vector<int>().swap(wok);	
		int x = i;
		while(x){
			wok.push_back(l2[(x & -x)]);
			x -= (x & -x);
		}
		//for(int x : wok) cout << x << " ";
		//cout << endl;
		if(wok.size() >= 3){
			for(int j = 1; j < wok.size() - 1; j++){
				int n = i ^ (1 << wok[j - 1]) ^ (1 << wok[j + 1]);
				if(pos[n] || ((n & curst) != curst)) continue;
				pos[n] = true;
				que.push(n);
				fromst[n] = i;
				del[n] = wok[j];
				if(n == curst){
					f = true;
					break;
				}
			}
		}

	}
		//cout << "curst = " << curst << endl;
	if(!pos[curst]){
		cout << -1 << endl;
		return;
	}
	vector<int> ans;
	vector<int>().swap(ans);
	while(curst != ((1 << N) - 1)){
		ans.push_back(del[curst]);
		curst = fromst[curst];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int x : ans) cout << x + 1 << " ";
	cout << endl;
}

void solve2(){
	cin >> M;
	fill(has, has + N, false);
	vector<int> ans;
	vector<int>().swap(ans);
	int x;
	for(int i = 0; i < M; i++){
		cin >> x;
		x--;
		has[x] = true;
	}
	int k = -1;
	for(int i = 1; i < N - 1; i++){
		if(has[i] && !has[i - 1] && !has[i + 1]){
			k = i;
		}
	}
	if(k == -1 && N != M){
		cout << -1 << endl;
		return;
	} else if(k == -1){
		cout << 0 << endl;
		return;
	}
	//cout << "k = " << k << endl;
	deque<int> l, r;
	for(int i = k - 1; i >= 0 && !has[i]; i--){
		//cout << "i = " << i << endl;
		l.push_front(i);
	}
	for(int i = k + 1; i < N && !has[i]; i++){
		//cout << "i = " << i << endl;
		r.push_back(i);
	}
	while(l.size() > 2){
		l.pop_front();
		int b = l.front();
		l.pop_front();
		l.pop_front();
		ans.push_back(b);
		l.push_front(b);
	}
	while(r.size() > 2){
		r.pop_front();
		int b = r.front();
		r.pop_front();
		r.pop_front();
		ans.push_back(b);
		r.push_front(b);
	}
	if(l.size() != r.size()){
		cout << -1 << endl;
	}
	while(l.size()){
		l.pop_back();
		r.pop_back();
		ans.push_back(k);
	}
	if((2 * ans.size() + M) != N){
		cout << -1 << endl;
		return;
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x + 1 << " ";
	cout << endl;
}

int main(){
	for(int i = 0; i < maxN; i++) l2[1 << i] = i;
	cin >> T;
	while(T--){
		cin >> N;
		if(N <= 18)
			solve();
		else solve2();
	}
}
