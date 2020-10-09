#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 326;
int T, N, arr[maxN], last;

class Cmp{
	public:
		const bool operator()(const int a, const int b) const {
			return arr[a] < arr[b];
		}
};

inline void solve(){
	priority_queue<int, vector<int>, Cmp> pq;	
	last = -1;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];	
		pq.push(i);
	}
	bool ct = 0;
	while(true){
		int mx = 0, mxAt = -1;
		for(int i = 0; i < N; i++){
			if(i == last) continue;
			if(mx < arr[i]){
				mx = arr[i];
				mxAt = i;
			}
		}
		if(mxAt == -1){
			break;
		}
		arr[mxAt]--;
		last = mxAt;
		ct ^= 1;
	}
	cout << (ct ? "T" : "HL") << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}

