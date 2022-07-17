#include <iostream>
#include <set>
using namespace std;

int N, M, x;
multiset<int> st;

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> x;
		st.insert(x);
	}
	while(M--){
		cin >> x; 
		auto it = st.upper_bound(x);
		if(it == st.begin()){
			cout << -1 << endl;
		} else {
			--it;
			cout << *it << endl;
			st.erase(it);
		}
	}
}
