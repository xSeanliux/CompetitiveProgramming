#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int main(){
	while(scanf("%d", &N) != EOF){
		if(!N) return 0;
		int k = 0;
		string s = "";
		while(N){
			s += (char)((N & 1) + '0');
			k += N & 1;
			N /= 2;
		}
		reverse(s.begin(), s.end());
		printf("The parity of %s is %d (mod 2).\n", s.c_str(), k); 
	}
}
