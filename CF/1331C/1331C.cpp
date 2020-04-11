#include <iostream>
#include <string.h>
using namespace std;

int perm[6] = {0, 5, 3, 2, 4, 1};

int main(){
	int N;
	cin >> N;
	string s;
	for(int i = 0; i < 6; i++){
		s = (char)('0' + ((N >> i) & 1)) + s;
	}
	int ans = 0;
	for(int i = 0; i < 6; i++){
		ans = ans * 2 + (s[perm[i]] - '0');
	}
	cout << ans << endl;
}
