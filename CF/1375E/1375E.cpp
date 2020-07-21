#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 226;
int N, arr[maxN], sorted[maxN];
vector<int> rev[maxN], ind;
vector<pii> ans;

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		sorted[i] = arr[i];
	}
	sort(sorted, sorted + N);
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			if(arr[i] > arr[j]) rev[i].push_back(j);
		}
	}
	for(int i = 0; i < N; i++){
		sort(rev[i].begin(), rev[i].end(), [](int a, int b){
			return (arr[a] == arr[b] ? a > b : arr[a] > arr[b]);	
		});
		for(int x : rev[i]){
			swap(arr[x], arr[i]);	
			ans.emplace_back(x + 1, i + 1);
		}
		for(int j = 0; j < N; j++){
			cout << arr[j] << " \n"[j == N - 1];
		}
	
	}
	for(int i = 1; i < N; i++){
		if(arr[i] < arr[i - 1]){
			cout << -1 << endl;
			return 0;
		}
	}
	for(auto [a, b] : ans){
		cout << a << " " << b << endl;
	}
}
