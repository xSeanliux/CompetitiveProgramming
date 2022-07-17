#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
using namespace std;

const int maxN = 2e5 + 326;

int N, K; 

int main(){
	cin >> N >> K;	
	ordered_set treap;
	for(int i = 0; i < N; i++){
		treap.insert(i);
	}
	int id = 0;
	for(int i = N; i; i--){
		id = (id + K) % i;
		auto it = treap.find_by_order(id);
		cout << (*it + 1) << endl;
		treap.erase(it);
	}
}
