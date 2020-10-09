#include <iostream>
#include <numeric>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326;
int N, ans[maxN], dsu[maxN];

void Flat(int x){
	if(x == dsu[x]) return;
	Flat(dsu[x]);
	ans[x] = ans[dsu[x]];
	dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(dsu[a] == dsu[b]) return;
	ans[dsu[a]] += ans[dsu[b]];
	dsu[dsu[b]] = dsu[a];
}

signed main(){
	cin >> N;
	iota(dsu, dsu + N + 1, 0);
	for(int i = 2; i <= N; i++){
		int k = 0;
		for(int j = 2 * i; j <= N; j+= i){
			Merge(i, j);
			//cout << "Merging " << j << " and " << i << ", ans += " << k << endl;
			k += 4 * j / i;
		}
		Flat(i);
		ans[dsu[i]] += k;
	}
	int r = 0;
	for(int i = 2; i <= N; i++){
		Flat(i);
		r = max(r, ans[i]);
	}
	cout << r << endl;
}
