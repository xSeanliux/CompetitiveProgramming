#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

int N, M, K, ans, x;
vector<pii> points;
deque<int> dq;

int main(){
	cin >> N >> M >> K;	
	for(int i = 0; i < N; i++){
		cin >> x;
		points.emplace_back(x + K, 2);
	}
	for(int i = 0; i < M; i++){
		cin >> x;
		points.emplace_back(x, 1);
	}
	sort(points.begin(), points.end());
	for(auto [p, t] : points){
		if(t == 1){
			dq.push_back(p);
		} else {
			while(dq.size() && dq.front() < p - 2 * K) dq.pop_front();
			if(dq.size()){
				ans++;
				dq.pop_front();
			}
		}
	}
	cout << ans << endl;
}
