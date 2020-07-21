#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

string a, b;
int m;

signed main(){
	cin >> a >> b >> m;
	if(a.length() >= b.length()) swap(a, b);
	while(a.length() < b.length()) a = '0' + a;
	int mult = 0, apre = 0, bpre = 0, da, db;
	for(int i = 0; i < a.length(); i++){
		da = a[i] - '0';
		db = b[i] - '0';
		mult = (100 * mult + 10 * apre * db + 10 * bpre * da + da * db) % m;
		apre = (apre * 10 + da) % m;
		bpre = (bpre * 10 + db) % m;
	}
	cout << mult % 2 << endl;
}
