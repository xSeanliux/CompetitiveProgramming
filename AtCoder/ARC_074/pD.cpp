#include <iostream>
#include <queue>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326;
int preM[maxN * 3], sufm[maxN * 3], arr[maxN * 3], ans = -1e18, N;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

signed main(){
	cin >> N;
	for(int i = 0; i < 3 * N; i++) cin >> arr[i];
	int s = 0;
	for(int i = 0; i < 3 * N; i++){
		s += arr[i];
		minHeap.push(arr[i]);
		if((int)minHeap.size() == N + 1){
			s -= minHeap.top();
			minHeap.pop();
		}
		preM[i] = s;
	}
	s = 0;
	for(int i = 3 * N - 1; i >= 0; i--){
		s += arr[i];
		maxHeap.push(arr[i]);
		if((int)maxHeap.size() == N + 1){
			s -= maxHeap.top();
			maxHeap.pop();
		}
		sufm[i] = s;
	}
	//for(int i = 0; i < 3 * N; i++) cout << preM[i] << " \n"[i == 3 * N - 1];
	//for(int i = 0; i < 3 * N; i++) cout << sufm[i] << " \n"[i == 3 * N - 1];
	for(int i = N - 1; i < 2 * N; i++){
		ans = max(ans, preM[i] - sufm[i + 1]);
	}
	cout << ans << endl;
}
