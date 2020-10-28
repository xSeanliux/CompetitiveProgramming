#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
int jizz[6], N, x, num[maxN], need, ans = 2e9;

vector<pii> vec;

inline void add(int x){
	if(!num[x]){
		need--;	
	}
	num[x]++;
} 

inline void rem(int x){
	if(num[x] == 1){
		need++;			
	}
	num[x]--;
}

int main(){
	for(int i = 0; i < 6; i++) cin >> jizz[i];
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x;
		for(int j = 0; j < 6; j++){
			vec.emplace_back(x - jizz[j], i);
		}
	}
	sort(vec.begin(), vec.end());
	int r = 1; need = N;
	add(vec[0].S);	
	for(int l = 0; l < (6 * N); l++){
		while(r < 6 * N && need) add(vec[r++].S);
		if(!need){
			ans = min(ans, vec[r - 1].F - vec[l].F);
		}
		rem(vec[l].S);
	}
	cout << ans << endl;
}
