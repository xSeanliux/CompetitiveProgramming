#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<int> v, dif;

int main(){
	cin >> N >> K;
	v.resize(N);
	for(int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for(int i = 1; i < N; i++) dif.push_back(v[i] - v[i - 1]);
	sort(dif.begin(), dif.end(), greater<int>());
	int ans = v[N - 1] - v[0] + 1;
	for(int i = 0; i < K - 1; i++){
		ans -= (dif[i] - 1);	
	}
	cout << ans << endl;
}
