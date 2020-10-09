#include <iostream>
#include <stack>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int maxN = 1e6 + 326, MOD = 1e9 + 7;
int T, N, K, L[maxN], W, H[maxN], A, B, C, D, c;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
	return (a > b ? a - b : a - b + MOD);
}

struct Obj{
	int L, R, H; 
	Obj(int L, int R, int H): L(L), R(R), H(H){}
	Obj(){}
} objs[maxN];

inline void solve(){
	cin >> N >> K >> W;
	for(int i = 0; i < K; i++){
		cin >> L[i];
	}
	cin >> A >> B >> C >> D;
	A %= D;
	B %= D;
	C %= D;
	for(int i = K; i < N; i++){
		L[i] = (A * L[i - 2] + B * L[i - 1] + C) % D + 1;	
		//cout << "L[" << i << "] = " << L[i] << endl;
	}
	for(int i = 0; i < K; i++){
		cin >> H[i];
	}
	cin >> A >> B >> C >> D;
	A %= D;
	B %= D;
	C %= D;
	//cout << "A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << endl;
	for(int i = K; i < N; i++){
		H[i] = (A * H[i - 2] + B * H[i - 1] + C) % D + 1;	
		//cout << "H[" << i << "] = " << H[i] << endl;
	}
	stack<Obj> stk;
	int per = 2 * (W + H[0]) % MOD, pd = 2 * (W + H[0]) % MOD;
	stk.push(Obj(L[0], L[0] + W, H[0]));
	//cout << "per[0] = " << per << endl;	
	for(int i = 1; i < N; i++){
		//cout << "[" << L[i] << ", " << L[i] + W << "], hei = " << H[i] << endl;
		while(stk.size() && stk.top().L >= L[i] && stk.top().H <= H[i]){
			//cout << "POP" << endl;
			per = sub(per, 2 * (stk.top().R - stk.top().L));
			stk.pop();
		}
		if(stk.top().R >= L[i]){
			if(stk.top().H >= H[i]){
				//cout << "CA" << endl;
				per = add(per, 2 * (L[i] + W - stk.top().R));
				//cout << "now per = " << per << endl;
				stk.push(Obj(stk.top().R, L[i] + W, H[i]));
			} else {
				Obj t = stk.top(); stk.pop();
				per = sub(per, 2 * (t.R - L[i]) + t.H);
				//cout << "Sub:" << 2 * (t.R - L[i]) + t.H << endl; 
				per += MOD;
				stk.push(Obj(t.L, L[i], t.H));
				stk.push(Obj(L[i], L[i] + W, H[i]));
				per = add(per, 2 * (W + H[i]) - t.H);
				//cout << "Add: " << 2 * (W + H[i]) - t.H << endl;
			}
		} else {
			per = add(per, 2 * (W + H[i]));
			stk.push(Obj(L[i], L[i] + W, H[i]));
		}
		per %= MOD;
		//cout << "per[" << i << "] = " << per << endl;
		pd = (pd * per) % MOD;
	}
	cout << "Case #" << ++c << ": " << pd << endl;
}

signed main(){
	ericxiao;
	cin >> T;
	while(T--){
		solve();
	}
}
