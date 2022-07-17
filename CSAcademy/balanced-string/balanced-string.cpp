#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e4 + 326;
int T;
bool vis[maxN];
string s;

inline int add(int a, int b, int m){
	return (a + b >= m ? a + b - m : a + b);
}

bool solve(string s){
	cout << "solving: " << s << endl;
	if(s.length() <= 1){
		return true;
	}
	string A = "", B = "";
	int aA = -1, bA = -1, minA = maxN, maxA = -1, minB = maxN, maxB = -1;
	fill(vis, vis + s.length(), false);
	for(int i = 0; i < s.length(); i++){
		int l = 0;
		for(int j = add(i, 1, s.length()); s[i] != s[j]; j = add(j, 1, s.length())){
			l++;
		}
		cout << "i = " << i << ", l = " << l << endl;
		if(s[i] == 'B'){
			if(aA == -1) aA = l;
			A += (aA == l) ? 'A' : 'B';
			minA = min(minA, l);
			maxA = max(maxA, l);
		} else {
			if(bA == -1) bA = l;
			B += (bA == l) ? 'A' : 'B';
			minB = min(minB, l);
			maxB = max(maxB, l);
			//cout << "i = " << i << ", l = " << l << endl;
		}
	}
	cout << "A = " << A << ", B = " << B << endl;
	//cout << "maxB = " << maxB << ", minB = " << minB << ", maxA = " << maxA << ", minA = " << minA << endl;
	if(maxB - minB > 1 || maxA - minA > 1) return false;
	if(A.length() < B.length()) return solve(A);
	else return solve(B);
}

int main(){
	cin >> T;
	while(T--){
		cin >> s;
		cout << solve(s) << endl;
	}
}
