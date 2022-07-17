#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

int N, a, b;

vector<pii> vec;

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		vec.emplace_back(a, b);
	}
	sort(vec.begin(), vec.end(), [](pii a, pii b){
		return a.S < b.S;
	});
	int cur = -1, ans = 0;
	for(auto [a, b] : vec){
		if(a >= cur){
			ans++;
			cur = b;
		}
	}
	cout << ans << endl;
}
