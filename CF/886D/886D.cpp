#include <iostream>
#include <string.h>
#include <algorithm>
#include <numeric>
using namespace std;

const int maxN = 1e5 + 326, W = 326; 
int nxt[W], prv[W], N, head, dsu[maxN];

string s, pot[maxN];
bool vis[maxN], appear[W];

void Flat(int x){
	if(x == dsu[x]) return;
	Flat(dsu[x]);
	dsu[x] = dsu[dsu[x]];
}

bool Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(dsu[a] == dsu[b]) return false;
	dsu[dsu[a]] = dsu[b];
	return true;
}

inline bool link(char a, char b){
	if(nxt[a] == b && prv[b] == a) return true;
	if((nxt[a] && nxt[a] != b) || (prv[b] && prv[b] != a)) return false;
	if(!Merge(a, b)) return false;
	nxt[a] = b;
	prv[b] = a;
	return true;
}

int main(){
	cin >> N;
	bool f = true;
	iota(dsu, dsu + W, 0);
	while(N--){
		cin >> s;
		for(char c : s) appear[c] = true;
		for(int i = 0; i < s.length() - 1; i++) f &= link(s[i], s[i + 1]);
	}
	if(!f){
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 'a'; i <= 'z'; i++){
		if(!appear[i]) continue;
		if(!prv[i]){
			string tmp = "";	
			int k = i;
			while(k){
				tmp += (char)k;
				k = nxt[k];
			}
			pot[head++] = tmp;
		}
	}
	sort(pot, pot + head);
	for(int i = 0; i < head; i++) cout << pot[i];
}

