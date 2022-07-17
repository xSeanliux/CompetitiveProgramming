#include <iostream>
#include <set>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second 
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int x, N, p;

set<pii> st;
multiset<int> lens;

int main(){
	ericxiao
	cin >> x >> N;
	st.insert({0, x});
	lens.insert(x);
	while(N--){
		cin >> p;
		auto it = --st.upper_bound({p, 2e9});
		//cout << "Found: " << it->F << " " << it->S << endl;
		lens.erase(lens.find(it->S - it->F));
		st.erase(it);
		pii L = {it->F, p}, R = {p, it->S};
		if(L.S - L.F > 0){
			lens.insert(L.S - L.F);
			//cout << "Ins: " << L.F << " " << L.S << endl;
			st.insert(L);
		}
		if(R.S - R.F > 0){
			lens.insert(R.S - R.F);
			//cout << "Ins: " << R.F << " " << R.S << endl;
			st.insert(R);
		}
		cout << *lens.rbegin() << '\n';
	}
}



