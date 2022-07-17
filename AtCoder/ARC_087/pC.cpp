#include <iostream>
#include <map>
using namespace std;

int N, x;

map<int, int> frq;

int main(){
	cin >> N;
	while(N--){
		cin >> x;
		frq[x]++;
	}
	int ans = 0;
	for(auto [a, b] : frq){
		ans += (a <= b ? b - a : b); 
	}
	cout << ans << endl;
}
