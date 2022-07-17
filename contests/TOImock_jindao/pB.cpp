#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2000 + 326;

int N, arr[maxN][maxN], val[maxN], cxor[maxN];
string s;

int main(){
	ericxiao;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < N; j++) arr[i][j] = s[j] - '0';
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		if(arr[i][j] != arr[j][i]){
			cout << -1 << endl;
			return 0;
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		int k = 1;
		for(int j = i; j < N; j++) arr[i][j] ^= cxor[j];
		for(int j = i + 1; j < N; j++){
			if(arr[i][j] != arr[i][j - 1]) k++;
		}
		if((k & 1) ^ (arr[i][i] == 1)) k--;
		ans += k;
		for(int j = i; j < N; j++) cxor[j] ^= arr[i][j];
	}
	cout << ans << endl;
}
