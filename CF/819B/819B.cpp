#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 226;
int N, delta, curdev, perm[maxN], d[maxN], dd[maxN], mindev = maxN * maxN, minAt;

inline int Abs(int x){
	return x < 0 ? -x : x;
}

inline int getDev(int s){
	int r = 0;
	for(int i = 0; i < N; i++){
		r += Abs(perm[(i - s + N) % N + 1] - i - 1);	
	}
	return r;
}

signed main(){
	ericxiao;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> perm[i];
		if(perm[i] == N && i == N){
			d[1] += N - 1;
			dd[1] += -1;
		} else if(perm[i] == i){
			dd[0] += 1;
			dd[N - i] += -1;
			d[N + 1 - i] += Abs(1 - perm[i]) - Abs(N - perm[i]);
			dd[N + 1 - i] += -1;
		} else if(i == N){
			d[0] += N - perm[i];
			d[1] += Abs(1 - perm[i]) - Abs(N - perm[i]);
			dd[1] += -1;
			dd[perm[i]] += 2;
		} else {
			d[0] += Abs(i - perm[i]);
			dd[0] += (i < perm[i] ? -1 : 1);
			dd[(perm[i] - i + N) % N] += 2;
			dd[N - i] += -1;
			d[N + 1 - i] += Abs(1 - perm[i]) - Abs(N - perm[i]);
			dd[N + 1 - i] += -1;
		}
	}
	for(int i = 0; i < N; i++){
		curdev += d[i];
		delta += dd[i];
		if(mindev > curdev){
			mindev = curdev;
			minAt = i;
		}
		curdev += delta;
	}
	cout << mindev << " " << minAt << '\n';
}
