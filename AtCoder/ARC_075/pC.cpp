#include <iostream>
using namespace std;

int N, x, sum, mm;

int main(){
	mm = 10000;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x;
		sum += x;
		if(x % 10) mm = min(mm, x);
	}
	if(sum % 10){
		cout << sum << endl;
		return 0;
	}
	if(mm == 10000){
		cout << 0 << endl;
	} else {
		cout << sum - mm << endl;
	}

}
