#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e3 + 326;
int wei[maxN][maxN], N, ans = 0, t;

int main(){
	ericxiao
	cin >> N;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> wei[i][j];
	t = 0;
	for(int i = 0; i < N; i++){
		int a = 0, b = 0;
		for(int j = 0; j < N; j++) (j & 1 ? a : b) += wei[i][j];
		t += max(a, b);
	}
	ans = t;
	t = 0;
	for(int j = 0; j < N; j++){
		int a = 0, b = 0;
		for(int i = 0; i < N; i++) (i & 1 ? a : b) += wei[i][j];
		t += max(a, b);
	}
	cout << max(ans, t) << endl;
}

