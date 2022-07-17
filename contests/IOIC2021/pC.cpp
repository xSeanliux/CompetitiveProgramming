#include <iostream>
#include <math.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 326;
int N, arr[maxN];

int main(){
	ericxiao;
	cin >> N;
	if(N == 1){
		cout << 2 << endl;
		return 0;
	}
	for(int i = 0; i < N; i++) cin >> arr[i];
	bool hasZ = 0;
	for(int i = 1; i < N; i++) if(arr[i - 1] == arr[i]) hasZ = 1;
	if(hasZ){
		cout << 2 << endl;
		return 0;
	}
	bool allO = 1;
	for(int i = 1; i < N; i++) if(abs(arr[i - 1] - arr[i]) != 1) allO = 0;
	if(allO){
		cout << 1 << endl;
		return 0;
	}
	cout << 0 << endl;
}
