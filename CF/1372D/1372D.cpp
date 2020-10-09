#include <iostream>
#include <deque>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;
deque<int> dq;

int N, x, ans;

signed main(){
	cin >> N;
	int t = 0, nt = 0;
	for(int i = 0; i < N; i++){
		cin >> x;
		dq.push_back(x);
		if(i > 1) (i % 2 ? t : nt) += x;
	}
	if(N == 1){
		cout << dq[0] << endl;
		return 0;
	}
	for(int i = 0; i < N; i++){
		ans = max(ans, t + dq[0] + dq[1]);	
		nt -= dq[2];
		t += dq[0];
		dq.push_back(dq.front());
		dq.pop_front();
		swap(nt, t);
	}
	cout << ans << endl;
}
