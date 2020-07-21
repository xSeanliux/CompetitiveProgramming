#include <iostream>
#include <algorithm>
#include <string.h>
#include <iomanip>
#define int long long int
using namespace std;

const int maxN = 2e5 + 226, W = 26;

string a, b;
double frq[maxN][W], ans;
int N; 

signed main(){
	cout << fixed << setprecision(10);
	cin >> N;
	cin >> a >> b;	
	for(int i = 0; i < N; i++){
		frq[i][b[i] - 'A'] += N - i;	
	}
	for(int i = N - 2; i >= 0; i--) for(int j = 0; j < W; j++) frq[i][j] += frq[i + 1][j];
	for(int i = 0; i < N - 1; i++){
		ans += (i + 1) * frq[i + 1][a[i] - 'A'];	
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < W; j++) frq[i][j] = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for(int i = 0; i < N; i++){
		frq[i][b[i] - 'A'] += N - i;
	}
	for(int i = N - 2; i >= 0; i--) for(int j = 0; j < W; j++) frq[i][j] += frq[i + 1][j];
	for(int i = 0; i < N - 1; i++){
		ans += (i + 1) * frq[i + 1][a[i] - 'A'];
	}

	for(int i = 0; i < N; i++){
		if(a[i] == b[i]){
			ans += (i + 1) * (N - i); 
		}
	}
	double denom = 0;
	for(int i = 1; i <= N; i++){
		denom += (N - i + 1) * (N - i + 1);	
	}
	cout << ans / denom << endl;
}
