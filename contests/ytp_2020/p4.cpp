#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string s;
int N, ans;

bool check(){
	for(int i = 1; i < N; i++){
		if(s[i] == s[i - 1]) return false;
	}
	return true;
}

int main(){
	cin >> N >> s;
	sort(s.begin(), s.end());
	do{
		ans += check();
	} while(next_permutation(s.begin(), s.end()));
	cout << ans << endl;
		

}
