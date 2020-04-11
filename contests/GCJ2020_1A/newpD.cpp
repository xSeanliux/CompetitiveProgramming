#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int, int>
#define F first
#define S second
#define int long long int
using namespace std; 

vector<vector<int> > l, r, u, d, arr;
vector<pii> toUpdate, nxtUpdate;
int T, N, M, c, x, cursum, ans;

pii getNei(int y, int x){
	pii res = {0, 0};
	if(r[y][x] != M){
		res.F++;
		res.S += arr[y][r[y][x]];
	}
	if(l[y][x] != -1){
		res.F++;
		res.S += arr[y][l[y][x]];
	}
	if(u[y][x] != -1){
		res.F++;
		res.S += arr[u[y][x]][x];
	}
	if(d[y][x] != N){
		res.F++;
		res.S += arr[d[y][x]][x];
	}
	return res;
}

inline void update(int y, int x){
	cursum -= arr[y][x];
	if(r[y][x] != M){
		l[y][r[y][x]] = l[y][x];
		toUpdate.emplace_back(y, r[y][x]);
	}
	if(l[y][x] != -1){
		r[y][l[y][x]] = r[y][x];
		toUpdate.emplace_back(y, l[y][x]);
	}
	if(u[y][x] != -1){
		d[u[y][x]][x] = d[y][x];
		toUpdate.emplace_back(u[y][x], x);
	}
	if(d[y][x] != N){
		u[d[y][x]][x] = u[y][x];
		toUpdate.emplace_back(d[y][x], x);
	}
}

inline void solve(){
	cin >> N >> M;
	cursum = 0;
	ans = 0;
	l.resize(N);
	r.resize(N);
	u.resize(N);
	d.resize(N);
	arr.resize(N);
	for(int i = 0; i < N; i++){
		l[i].resize(M);
		r[i].resize(M);
		u[i].resize(M);
		d[i].resize(M);
		arr[i].resize(M);
		for(int j = 0; j < M; j++){
			cin >> x;
			cursum += x;
			l[i][j] = (j - 1);
			r[i][j] = (j + 1);
			u[i][j] = (i - 1);
			d[i][j] = (i + 1);
			arr[i][j] = (x);
		}
	}
	/*
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << "for " << i << ", " << j << ": " << endl;
			cout << "l = " << l[i][j] << endl;
			cout << "r = " << r[i][j] << endl;
			cout << "u = " << u[i][j] << endl;
			cout << "d = " << d[i][j] << endl;
		}
	}
	*/
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			pii res = getNei(i, j);	
			toUpdate.emplace_back(i, j);
		}
	}
	bool f = true;
	while(f){
		f = false;
		ans += cursum;	
		//cout << "cursum = " << cursum << endl;
		for(pii p : toUpdate){
			pii res = getNei(p.F, p.S);
			cout << "For " << p.F << ", " << p.S << ": " << res.F << " neis, sum = " << res.S  << endl;
			if(arr[p.F][p.S] * res.F < res.S){
				cout << "Deleting " << p.F << ", " << p.S << endl;
				nxtUpdate.emplace_back(p.F, p.S);
				f = true;
			}
		}
		vector<pii>().swap(toUpdate);
		for(pii p : nxtUpdate){
			update(p.F, p.S);
		}
		vector<pii>().swap(nxtUpdate);
	}
	vector<vector<int> >().swap(l);
	vector<vector<int> >().swap(r);
	vector<vector<int> >().swap(u);
	vector<vector<int> >().swap(d);
	vector<vector<int> >().swap(arr);
	cout << "Case #" << ++c << ": " << ans << endl;
}
signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
