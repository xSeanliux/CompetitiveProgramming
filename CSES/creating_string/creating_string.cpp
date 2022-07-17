#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

string s;
vector<string> ans;

int main(){
	cin >> s;
	sort(s.begin(), s.end());
	ans.push_back(s);
	while(next_permutation(s.begin(), s.end())) ans.push_back(s);
	cout << ans.size() << endl;
	for(string S : ans) cout << S << endl;
}
