#include <iostream>
#define int long long int
using namespace std;

int N, x;

signed main(){
	cin >> N;
	while(N--){
		cin >> x;
		int jizz = x;
		int k = 0;
		while(x){
			k += x  % 10;
			x /= 10;
		}
		cout << jizz * k << '\n';
	}
}
