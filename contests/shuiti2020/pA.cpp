#include <iostream>
using namespace std;

int m;

int main(){
	cin >> m;
	if(m < 100){
		printf("00\n");
		return 0;
	}
	if(m < 5000){
		printf("%02d\n", m / 100);
		return 0;
	}
	if(m < 30000){
		printf("%d\n", m/1000 + 50);
		return 0;
	}
}
