#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define endl '\n'
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxC = 1e6 + 10, maxN = 1e5 + 10, maxS = 1e3 + 226;

vector<int> primes, pri, exp, vals, factors[maxN];
bool isPrime[maxS];
int N, curf;
pii minVal[maxC], secMin[maxC];

void init(){
	fill(isPrime, isPrime + maxS, true);
	for(int i = 2; i < maxS; i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
		for(int p : primes){
			if(i * p >= maxS) break;
			isPrime[i * p] = false;
			if(!(i % p)) break;
		}
	}
}


void dfs(int ci, int now = 0, int fval = 0, int curnum = 1){
	if(now == pri.size()){
		//cout << "Generated factor: " << curnum << endl;
		pii p = {curf - 2 * fval, ci};
		if(p < minVal[curnum]){
			secMin[curnum] = minVal[curnum];
			minVal[curnum] = p;
		} else if(p < secMin[curnum]){
			secMin[curnum] = p;
		}
		factors[ci].push_back(curnum);
		//cout << curnum << " has fval " << fval << endl;
		return;
	}
	int r = 1;
	//cout << "Current factor: " << pri[now] << endl;
	for(int i = 0; i <= exp[now]; i++){
		dfs(ci, now + 1, fval + i, curnum * r);
		r *= pri[now];
	}
}

void runNum(int x, int idx){
	int _x = x;
	curf = 0;
	vector<int>().swap(pri);
	vector<int>().swap(exp);
	for(int p : primes){
		if(p * p > _x) break;
		if(!(_x % p)){
			pri.push_back(p);
			exp.push_back(0);
			while(!(_x % p)){
				_x /= p;
				exp[exp.size() - 1]++;
				curf++;
			}
		}
	}
	if(_x > 1){
		pri.push_back(_x);
		exp.push_back(1);
		curf++;
	}
	dfs(idx);
}

int main(){
	ericxiao;
	cin >> N;
	vals.resize(N);
	for(int i = 0; i < maxC; i++){
		minVal[i] = {maxC, -1};
		secMin[i] = {maxC + 1, -1};
	}
	init();
	for(int i = 0; i < N; i++){
		cin >> vals[i];
		runNum(vals[i], i);
	}
	for(int i = 0; i < N; i++){
		pii p = {maxC, -1};
		for(int d : factors[i]){
			if(minVal[d].S != i) p = min(p, minVal[d]);
			if(secMin[d].S != i) p = min(p, secMin[d]);
		}
		cout << p.S + 1 << endl;
	}
}
