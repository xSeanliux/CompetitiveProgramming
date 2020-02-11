#include <iostream>
#define int long long int
using namespace std;

int q, a, b, n, S;
signed main(){
	cin >> q;
	while(q--){
		cin >> a >> b >> n >> S;
		if(a * n + b >= S && S % n <= b){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
