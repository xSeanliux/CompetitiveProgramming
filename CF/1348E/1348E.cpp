#include <iostream>
#define int long long int
using namespace std;

const int maxN = 500 + 226;
int A, B, N, K, a[maxN], b[maxN], ans, usedA[maxN], baskets[maxN], nxtBaskets[maxN];
bool isPossible[maxN], nxtPossible[maxN];
signed main(){
	cin >> N >> K;
	isPossible[0] = true;
	for(int i = 0; i < N; i++){
		cin >> a[i] >> b[i];
		A += a[i];
		B += b[i];
		a[i] = min(a[i], K);
		b[i] = min(b[i], K);
		for(int j = 0; j < K; j++){
			nxtPossible[j] = isPossible[j];
			nxtBaskets[j] = baskets[j];
		}
		for(int x = 0; x < K; x++){
			if(x <= a[i] && K - x <= b[i]){
				for(int j = 0; j < K; j++){
					if(isPossible[j]){
						nxtPossible[(j + x) % K] = true;
						nxtBaskets[(j + x) % K] = max(nxtBaskets[(j + x) % K], baskets[j] + 1);
					}
				}
			}
		}
		for(int j = 0; j < K; j++){
			isPossible[j] = nxtPossible[j];
			baskets[j] = nxtBaskets[j];
		}
	}
	//cout << "A = " << A << ", B = " << B << endl;
	for(int i = 0; i < K; i++){
		if(nxtPossible[i]){
			//cout << "Pos: " << i << ", bsk: " << nxtBaskets[i] << endl;
			if(nxtBaskets[i] > 0){
				ans = max(ans, (A - i) / K + (B - (K - i)) / K + 1);
			} else {
				ans = max(ans, A / K + B / K);
			}
		}
	}
	cout << ans << endl;
}
