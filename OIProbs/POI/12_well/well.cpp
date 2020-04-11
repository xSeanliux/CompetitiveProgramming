#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10, INF = 1e18 + 10;
int arr[maxN], h[maxN], N, mv, pre[maxN];

inline int check(int d){
	//cout << "Checkign " << d << endl;
	for(int i = 1; i <= N; i++){
		h[i] = arr[i];
	}
	int rq = 0;
	for(int i = 2; i <= N; i++){
		if(h[i] > h[i - 1] && h[i] - h[i - 1] > d){
			rq += h[i] - h[i - 1] - d;	
			h[i] = h[i - 1] + d;
		}
	}
	for(int i = N - 1; i >= 1; i--){
		if(h[i] > h[i + 1] && h[i] - h[i + 1] > d){
			rq += h[i] - h[i + 1] - d;
			h[i] = h[i + 1] + d;
		}
	}
	if(rq > mv) return 0;
	/*
	for(int i = 1; i <= N; i++){
		cout << h[i] << " ";
	}
	cout << endl;
	*/
	for(int i = 1; i <= N; i++)
		pre[i] = pre[i - 1] + h[i];
	
	int minRq = INF, minAt = -1;
	//cout << "Cur rq = " << rq << endl;
	for(int i = 1, l = 0, r = 2; i <= N; i++){
		while(l <i - 1 && (i - l - 1) * d >= h[l + 1]) l++; 	
		while(r == i || r <= N && (r - i) * d < h[r]) r++;
		if(minRq > pre[r - 1] - pre[l] - ((i - l - 1) * (i - l) * d / 2 + (r - i - 1) * (r - i) * d / 2)){
			minRq = pre[r - 1] - pre[l] - ((i - l - 1) * (i - l) * d / 2 + (r - i - 1) * (r - i) * d / 2);
			minAt = i;
		}
		//cout << "For i = " << i << ", l = " << l << ", r = " << r << endl;
		//cout << "Rq: " << pre[r - 1] - pre[l] - ((i - l - 1) * (i - l) * d / 2 + (r - i - 1) * (r - i) * d / 2) << endl;
	}
	return (minRq + rq <= mv ? minAt : 0);
}

signed main(){
	ericxiao;
	cin >> N >> mv;
	for(int i = 1; i <= N; i++) cin >> arr[i];
	int L = -1, R = INF, M;
	while(L + 1 < R){
		M = (L + R) / 2;
		if(check(M)) R = M;
		else L = M;
	}
	cout << check(R) << " " << R << endl;
}
