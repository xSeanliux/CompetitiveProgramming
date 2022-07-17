#include <iostream>
using namespace std;

inline int lb(int x){
	return x & (-x);
}

inline bool can(string a, string b){
	//if(a.length() <= 5) cout << "running " << a << ", " << b << endl;
	if(a.length() == 1 && b.length() == 1){
		return a[0] == b[0];
	}
	if(a[0] == '1' && b[0] == '0') return false;
	if(a[0] == b[0]) return can(a.substr(1), b.substr(1));
	//0....
	//1....
	int ca = 0, cb = 0;
	for(int i = 0; i < a.length(); i++){
		ca += a[i] == '1';
		cb += b[i] == '1';
	}
	if(ca < cb) return false;
	int k = 0;
	for(int i = 0; i < a.length() && k < (ca - cb) + 1; i++){
		if(a[i] == '1'){
			a[i] = '0';
			k++;
		}
	}
	return can(a.substr(1), b.substr(1));	
}

int main(){
	int Q, u, v;
	cin >> Q;
	while(Q--){
		cin >> u >> v;
		if(u > v){
			cout << "No\n";
			continue;
		}
		string a = "", b = "";
		for(int i = 29; i >= 0; i--){
			a += (char)('0' + ((u >> i) & 1));
			b += (char)('0' + ((v >> i) & 1));
		}
		if(can(a, b)) cout << "YEs\n";
		else cout << "No\n";
	}
}
