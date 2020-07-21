#include <iostream>
#include <complex>
#include <algorithm>
#include <math.h>
#include <vector>
#define cd complex<double>
using namespace std;

const double PI = acos(-1);
vector<cd> fft(vector<cd> &vec, bool inv = false){
	if(vec.size() == 1) return vec;	
	vector<cd> res[2], ret(vec.size());
	for(int i = 0; i < vec.size(); i++){
		res[i & 1].push_back(vec[i]);	
	}
	res[0] = fft(res[0], inv);
	res[1] = fft(res[1], inv);
	double theta = (inv ? -1 : 1) * 2 * PI / vec.size();
	cd omega(cos(theta), sin(theta)), now = 1;
	for(int i = 0; i < vec.size() / 2; i++){
		ret[i] = res[0][i] + now * res[1][i];	
		ret[i + vec.size() / 2] = res[0][i] - now * res[1][i];
		now *= omega;
	}
	if(inv) for(int i = 0; i < vec.size(); i++) ret[i] /= 2; 
	return ret;
}

vector<cd> mult(vector<cd> A, vector<cd> B){
	int l = 1;
	for(;; l <<= 1){
		if(l >= max(A.size(), B.size())) break;
	}
	l <<= 1;
	while(A.size() < l) A.push_back(0);
	while(B.size() < l) B.push_back(0);
	vector<cd> fA = fft(A), fB = fft(B);
	for(int i = 0; i < l; i++){
		fA[i] *= fB[i];
	}
    return fft(fA, true);
}

const int maxN = 2e5 + 10;
int N, x, k, arr[maxN];
vector<cd> A, B;

int main(){
	cin >> N >> x; 	
	A = B = vector<cd>(N + 1);
	int cnt = 0;
	A[0] = 1;
	for(int i = 0; i < N; i++){
		cin >> k;
		if(k < x){
			cnt++;
		}
		A[cnt] += 1;
		B[cnt] += 1;
	}
	long long int jizz = 0;
	for(int i = 0; i < N; i++) jizz += A[i].real() * (A[i].real() - 1) / 2;
	
	reverse(B.begin(), B.end());
	vector<cd> ans = mult(A, B);
	cout << jizz;
	for(int i = N - 1; i >= 0; i--) cout << " " << (long long int)(round(ans[i].real()));
	cout << endl;
}
