#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxK = 40;

int basis[maxK];

struct Obj{
	int a, b;
	char c;
	Obj(){}
	Obj(int a, char c, int b): a(a), c(c), b(b){};
};

vector<Obj> ans;
vector<int> v;

bool can(int x){
	for(int k = maxK - 1; k >= 0; k--){
		if(!((x >> k) & 1)) continue;
		if(!basis[k]) return true;
		x ^= basis[k];
	}
	return false;
}

void insert(int x){
	int orix = x;
	for(int k = maxK - 1; k >= 0; k--){
		if(!((x >> k) & 1)) continue;
		if(!basis[k]){
			basis[k] = x;
			return;
		}
		x ^= basis[k];
	}
}

void insert_back(int x){
	int orix = x;
	for(int k = maxK - 1; k >= 0; k--){
		if(!((x >> k) & 1)) continue;
		if(!basis[k]){
			for(int l = maxK - 1; l > k; l--){
				if(!((orix >> l) & 1)) continue;
				ans.emplace_back(orix, '^', basis[l]);
				//cout << orix << " ^ " << basis[l] << endl;
				orix ^= basis[l];
			}
			basis[k] = x;
			return;
		}
		x ^= basis[k];
	}
}

int x;

signed main(){
	cin >> x;
	int k = x;
	ans.emplace_back(x, '^', x);
	while(!basis[0]){
		if(can(k)){
			v.push_back(k / x);		
			//cout << "have: " << k / x << endl;
			insert(k);
		}
		k += x;
	}
	fill(basis, basis + maxK, 0);
	for(int i = x; 2 * i < (1LL << maxK); i *= 2){
		ans.emplace_back(i, '+', i); 
	}
	for(int k : v){
		int cnt = 0;
		for(int i = 0; i < maxK; i++){
			if((k >> i) & 1){
				ans.emplace_back(cnt, '+', x * (1 << i));
				cnt += x * (1 << i);
			}
		}
		insert_back(k * x);
		//cout << "adding: " << k * x << endl;
	}
	cout << ans.size() << endl;
	for(auto o : ans){
		cout << o.a << " " << o.c << " " << o.b << endl;
	}
}
