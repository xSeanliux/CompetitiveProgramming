#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 326;
int N, arr[maxN];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	cout << unique(arr, arr + N) - arr << endl;
}
