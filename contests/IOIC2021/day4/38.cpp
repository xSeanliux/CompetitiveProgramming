#include <iostream>
using namespace std;

int T, n, m;

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		if(m - n == 1) cout << "Zweite" << endl;
		else cout << "Erste" << endl;
	}
}
