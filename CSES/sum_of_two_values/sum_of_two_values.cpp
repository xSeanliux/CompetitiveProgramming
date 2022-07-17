#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
int N, x; 
pii arr[maxN];

int main(){
	cin >> N >> x;
	for(int i = 0; i < N; i++){
		cin >> arr[i].F;
		arr[i].S = i + 1;
	}
	sort(arr, arr + N);
	int r = N - 1;
	for(int l = 0; l < r; l++){
		while(r - l > 1 && arr[l].F + arr[r].F > x) r--;
		if(arr[l].F + arr[r].F == x){
			cout << arr[l].S << " " << arr[r].S << endl; 
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
