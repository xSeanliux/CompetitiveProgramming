#include <iostream>
#include <set>
#define int long long int
using namespace std;

int ans[14] = {-1, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341, 390};
/*
int gen(int x){
	set<int> st;
	for(int i = 0; i < (1 << (2 * x)); i++){
		int t = i, sum = 0;
		for(int j = 0; j < x; j++){
			if(t % 4 == 0){
				sum += 1;	
			} else if(t % 4 == 1){
				sum += 5;
			} else if(t % 4 == 2){
				sum += 10;
			} else {
				sum += 50;
			}
			t /= 4;
		}
		st.insert(sum);
	}
	return st.size();
}
*/
int N;
signed main(){
	cin >> N;
	if(N <= 13){
		cout << ans[N] << endl; 
	} else {
		cout << ans[12] + (N - 12) * (ans[13] - ans[12]) << endl; //lol its linear
	}
}
