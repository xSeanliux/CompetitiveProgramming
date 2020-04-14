#include <iostream>
#define int long long int
using namespace std;

int T, N, arr[50];

struct Triple{
	int a, b, c;
	Triple(){}
	Triple(int a, int b, int c): a(a), b(b), c(c){}
};

Triple getNum(int trip, int iter = 30){
	if(!trip) return Triple(0, 0, 0);	
	if(trip < (1LL << (iter * 2))) return getNum(trip, iter - 1); 
	Triple res = getNum(trip % (1LL << (iter * 2)), iter - 1);
	if(trip / (1LL << (iter * 2)) == 1){
		return Triple(res.a + (1LL << (iter * 2)), res.b + (1LL << (iter * 2 + 1)), res.c + (1LL << (iter * 2)) + (1LL << (iter * 2 + 1))); 		
	} else if(trip / (1LL << (iter * 2)) == 2){
		return Triple(res.a + (1LL << (iter * 2 + 1)), res.b + (1LL << (iter * 2)) + (1LL << (iter * 2 + 1)), res.c + (1LL << (iter * 2)));
	} else {
		return Triple(res.a + (1LL << (iter * 2 + 1)) + (1LL << (iter * 2)), res.b + (1LL << (iter * 2)), res.c + (1LL << (iter * 2 + 1)));
	}
}
void solve(){
	N--;
	int cnt = N % 3, num = N / 3, res = 0, l = 0;
	for(; l < 30; l++){
		if(num < arr[l]) break;
		num -= arr[l];
	}
	Triple r = getNum(num);
	if(cnt == 0){
		res += (1LL << (2 * l)) + r.a;
	} else if(cnt == 1){
		res += (1LL << (2 * l + 1)) + r.b;	
	} else {
		res += (1LL << (2 * l)) + (1LL << (2 * l + 1)) + r.c;
	}
	cout << res << endl;
}

signed main(){
	for(int i = 0; i < 30; i++){
		arr[i] = (1LL << (2 * i));
	}
	cin >> T;
	while(T--){
		cin >> N;
		solve();
	}
}
