#include <iostream>
using namespace std;

int n;

int main(){
	cin >> n;
	cout << 3 * n + 4 << endl;
	cout << "0 0\n0 1\n1 0\n1 1\n";
	for(int i = 2; i < n + 2; i++){
		cout << i << " " << i << endl;
		cout << i - 1 << " " << i << endl;
		cout << i << " " << i - 1 << endl;
	}
}
