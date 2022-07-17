#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 326;
int N, x;
double arr[maxN];

int main(){
	while(cin >> N){
		if(!N) return 0;
		for(int i = 0; i < N; i++){
			cin >> x;
			arr[i] = x;
		}
		sort(arr, arr + N);
		double jizz = 0;
		for(int i = 1; i < N - 1; i++) jizz += arr[i];
		printf("%.2f\n", jizz / (N - 2));
	}
}
