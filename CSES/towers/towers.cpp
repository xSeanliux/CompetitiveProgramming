#include <iostream>
#include <set>
using namespace std;

multiset<int> st;

int N, x;

int main(){
	cin >> N;
	while(N--){
		cin >> x;
		auto it = st.upper_bound(x);
		if(it != st.end()) st.erase(it);
		st.insert(x);
	}
	cout << st.size() << endl;
}
