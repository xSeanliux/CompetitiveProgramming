#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	cout << fixed << setprecision(0);	cout << 1500 << endl;
	for(int i = 0; i < 500; i++){
		cout << 0 << " " << i * 100 << endl; 
	}
	for(int i = 0; i < 500; i++){
		cout << 1 << " " << i * 100 + 1e7 << endl;
	}
	for(int i = 0; i < 500; i++){
		cout << 2 << " " << i * 100 << endl; 
	}
}
