#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

const int maxN = 1e5 + 326;
int T, N, arr[maxN], Q, k, x, z;

int main(){
	cin >> N >> Q;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];	
		if(arr[i] == 0) z++;
	}
	while(Q--){
		cin >> k;
		if(k == 1){
			cin >> x;
			z -= (arr[x] == 0);
			arr[x] ^= 1;
			z += (arr[x] == 0);
		} else {
			cin >> x;
			if(x <= N - z) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
}
