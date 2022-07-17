#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 1e3 + 326;

struct BIT2{
	struct BIT{
		int bit[maxN];
		void add(int p, int v){
			for(; p < maxN; p += (p & -p)) bit[p] += v;				
		}
		inline int sum(int p){
			int r = 0;
			for(; p; p -= (p & -p)) r += bit[p];
			return r;
		}
	} bits[maxN];
	void add(int y, int x, int v){
		for(; y < maxN; y += (y & -y)) bits[y].add(x, v);
	}
	inline int sum(int y, int x){
		if(!y || !x) return 0;
		int r = 0;
		for(; y; y -= (y & -y)) r += bits[y].sum(x);
		return r;
	}
} bit;

int N, Q, com, a, b, c, d, arr[maxN][maxN];
string s;

int main(){
	cin >> N >> Q;
	for(int i = 1; i <= N; i++){
		cin >> s;
		for(int j = 1; j <= N; j++) if(s[j - 1] == '*'){
			bit.add(i, j, 1);
			arr[i][j] = 1;
		}
	}
	while(Q--){
		cin >> com;
		if(com == 1){
			cin >> a >> b;
			if(arr[a][b]){
				bit.add(a, b, -1);
			} else bit.add(a, b, 1);
			arr[a][b] ^= 1;
		} else {
			cin >> a >> b >> c >> d;
			cout << bit.sum(c, d) - bit.sum(a - 1, d) - bit.sum(c, b - 1) + bit.sum(a - 1, b - 1) << endl;
		}
	}
}
