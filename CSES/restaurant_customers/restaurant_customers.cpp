#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

int N, a, b, s, ans;
vector<pii> vec;

int main(){
	cin >> N;
	while(N--){
		cin >> a >> b;
		vec.emplace_back(a, 1);
		vec.emplace_back(b, -1);
	}
	sort(vec.begin(), vec.end());
	for(auto [_, ds] : vec){
		s += ds;
		ans = max(ans, s);
	}
	cout << ans << endl;
}
