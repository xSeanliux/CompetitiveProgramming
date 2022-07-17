#include <iostream>
#include <deque>
#include <cassert>
#include <map>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;

int N, K, arr[maxN], dp[maxN][2], nxtdp[maxN][2];
vector<int> lens;
deque<int> dq;

signed main(){
	cin >> N >> K;	
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}	
	int ext = N % K;
	for(int i = ext; i <= N; i += K) if(i) lens.push_back(i);
	for(int l : lens){
		if(l <= K){
			for(int i = 1; i + l - 1 <= N; i++){
				dp[i][0] = arr[i + l - 1] - arr[i - 1];
				dp[i][1] = 0;
			}
		} else {
			dq = deque<int>();
			for(int i = 1; i <= 1 + K; i++){
				while(dq.size() && -dp[dq.back()][0] < -dp[i][0]) dq.pop_back();
				dq.push_back(i);
			}
			for(int i = 1; i + l - 1 <= N; i++){ //l = i, r = i + K (inclusive)
				while(dq.front() < i) dq.pop_front();
				nxtdp[i][0] = arr[i + l - 1] - arr[i - 1] - dp[dq.front()][0];
				nxtdp[i][1] = dp[dq.front()][0];
				while(dq.size() && -dp[dq.back()][0] < -dp[i + K + 1][0]) dq.pop_back();
				dq.push_back(i + K + 1);
			}
			for(int i = 1; i + l - 1 <= N; i++){
				dp[i][0] = nxtdp[i][0];
				dp[i][1] = nxtdp[i][1];
			}
		}
	}
	cout << dp[1][0] << " " << dp[1][1] << endl;
}
