#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
const long long int MOD = 1e9 + 7;
const int maxN = 2e5 + 326;
int N, A[maxN], B[maxN], col[maxN], isIn[maxN], arr[maxN]; 
 
inline long long int mpow(long long int b, int e){
	long long int r = 1;
	for(int i = 0; i < 32; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}
 
struct Query{
	int l, r, id;
	Query(){}
	Query(int l, int r, int id): l(l), r(r), id(id){}
}; 
 
vector<Query> ques;
bool has[maxN << 2][2];
vector<int> adj[maxN], seg[maxN << 2];
 
int query(int id, int l, int r, int p, int u){
	int res = -1;
	for(int v : seg[id]){
		adj[u].push_back(v);
		adj[v].push_back(u);
		res = r;
	}
	if(seg[id].size() > 1){
		seg[id].erase(seg[id].begin() + 1, seg[id].end());
	}
	if(l + 1 == r) return res;
	int m = (l + r) / 2;
	if(p < m) return max(res, query(2 * id + 1, l, m, p, u));
	else return max(res, query(2 * id + 2, m, r, p, u));
}
 
void modify(int id, int l, int r, int ql, int qr, int u){
	if(l >= qr || ql >= r) return;
	if(ql <= l && r <= qr){
		seg[id].push_back(u);
		return;
	}
	int m = (l + r) / 2;
	modify(2 * id + 1, l, m, ql, qr, u);
	modify(2 * id + 2, m, r, ql, qr, u);
}
 
void dfs(int now, int c = 0){
	col[now] = c;	
	for(int v : adj[now]) if(col[v] == -1){
		dfs(v, c ^ 1);
	}
}
 
bool query2(int id, int l, int r, int p, int c){
	if(has[id][c]) return false;
	if(l + 1 == r) return true;
	int m = (l + r) / 2;
	if(p < m) return query2(2 * id + 1, l, m, p, c);
	else return query2(2 * id + 2, m, r, p, c);
}
 
void modify2(int id, int l, int r, int ql, int qr, int c){
	if(l >= qr || ql >= r) return;
	if(ql <= l && r <= qr){
		has[id][c] = 1;
		return;
	}
	int m = (l + r) / 2;
	modify2(2 * id + 1, l, m, ql, qr, c);
	modify2(2 * id + 2, m, r, ql, qr, c);
}
 
inline int isValid(){
	int cnt = 0;
	fill(col, col + N + 1, -1);
	/*	
	cout << "Conn: " << endl;
	
	for(int i = 1; i <= N; i++){
		cout << "u = " << i << ": "; for(int v : adj[i]) cout << v << ", "; cout << endl;
	}
	*/
	
	for(int i = 1; i <= N; i++) if(col[i] == -1){
		cnt++;
		dfs(i);
	}
	//for(int i = 1; i <= N; i++) cout << "col[" << i << "] = " << col[i] << endl;
	//cout << "cnt = " << cnt << endl;
	for(auto [l, r, id] : ques){
		if(!query2(0, 1, 2 * N + 1, l, col[id])) return -1;
		modify2(0, 1, 2 * N + 1, l, r + 1, col[id]);
	}
	return cnt;
}

void solve() {
    cin >> N;
    fill(A, A + N + 1, -1);
    fill(B, B + N + 1, -1);
    ques = vector<Query>();
    for(int i = 0; i < maxN * 4; i++) {
        has[i][0] = 0;
        has[i][1] = 0;
        seg[i].clear();
    }
    for(int i = 0; i < maxN; i++) {
        adj[i] = vector<int>();
        col[i] = isIn[i] = arr[i] = 0;
    }
    int x;
    for(int i = 1; i <= 2 * N; i++) {
        cin >> x;
        if(A[x] == -1) A[x] = i;
        else B[x] = i;
    }
    for(int i = 1; i <= N; i++){
        arr[A[i]] = arr[B[i]] = i;
        ques.emplace_back(A[i], B[i], i);
    }
    sort(ques.begin(), ques.end(), [](const Query &a, const Query &b){
        return a.r < b.r;
    });
    for(auto [l, r, id] : ques){
        int q = query(0, 1, 2 * N + 1, l, id);
        modify(0, 1, 2 * N + 1, max(q, l), r + 1, id);
    }
    int res = isValid();
    if(res == -1) {
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
    }
}
 
int main(){
    int T;
	ericxiao;
    cin >> T;
    while(T--) {
        solve();
    }
}
