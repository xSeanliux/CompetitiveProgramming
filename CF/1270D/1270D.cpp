#include <iostream>
#include <map>
#define F first
#define S second
using namespace std;

int k, n, pos, valpos;
map<int, int> mp;

int main(){
	cin >> n >> k;
	if(k == 1){
		cout << "! 1" << endl;
		return 0;
	} 
	for(int skip = 1; skip <= k + 1; skip++){
		cout << "?";
		for(int i = 1; i <= k + 1; i++){
			if(i != skip) cout << " " << i;
		}
		cout << endl;
		cin >> pos >> valpos;
		mp[valpos]++;
	}
	cout << "! " << mp.rbegin()->second << endl;
	return 0;
}

