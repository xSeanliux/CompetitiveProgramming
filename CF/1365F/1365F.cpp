#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

vector<int> a, b, c;
vector<pii> A, B;
int n, t;




void solve(){
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	vector<pii>().swap(A);
	vector<pii>().swap(B);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	if(n % 2 && a[n / 2] != b[n / 2]){
		cout << "No\n";
		return;
	}
	for(int i = 0; i < n / 2; i++){
		A.emplace_back(min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1]));	
		B.emplace_back(min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1]));	
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for(int i = 0; i < n / 2; i++){
		if(A[i] != B[i]){
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main(){
	cin >> t;
	while(t--){
		solve();
	}
}
