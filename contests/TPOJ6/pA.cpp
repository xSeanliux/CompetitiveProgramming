#include <iostream>
#include <string.h>
using namespace std;

int N;
string s;
bool can[26];

int main(){
	cin >> N;
	while(N--){
		cin >> s;
		if(s.length() == 1){
			can[s[0] - 'a'] = 1;
		}
	}
	for(int i = 0; i < 26; i++){
		if(!can[i]){
			cout << (char)(i + 'a') << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
