#include <iostream>
#include <utility>
#include <algorithm>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int INF = 1e18;
int C, L, N;
int ans = INF;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

pii extgcd(int a, int b) {
	if (b == 0) return pii(1, 0);
	pii t = extgcd(b, a%b);
	return pii(t.ss, t.ff - t.ss * (a/b));
}

int rev(int a) {
	return ((extgcd(a, N*N).ff % N) + N) % N;
}

signed main() {
	cin >> C >> L >> N;
	int k = C % N;
	for (int i = 1; i < N; i++) {
		if (rev(i * N + 1) * C % N == C % N) {
			cout << i << endl;
			return 0;
		}
	}
}
