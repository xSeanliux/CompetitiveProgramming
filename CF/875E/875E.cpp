#include <iostream>
#include <algorithm>
#include <deque>
#include <set>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 26, maxLog = 20;
int N, s1, s2, coords1[maxN], coords2[maxN], mxSparse[maxLog][maxN], minSparse[maxLog][maxN], maxGo[maxN];

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}



inline int Abs(int x){
	return (x < 0 ? -x : x);
}

struct Seg{
	int seg[maxN * 4], tag[maxN * 4];
	void pull(int id){
		seg[id] = seg[2 * id + 1] | seg[2 * id + 2];
	}
	void push(int id, int l, int r){
		seg[id] |= tag[id];
		if(l + 1 < r){
			tag[2 * id + 1] |= tag[id];
			tag[2 * id + 2] |= tag[id];
		}
		tag[id] = 0;
	}
	int query(int id, int pos, int l, int r){
		push(id, l, r);
		if(l + 1 == r){
			return seg[id];
		}
		int m = (l + r) / 2;
		if(pos < m){
			return query(2 * id + 1, pos, l, m);
		}
		return query(2 * id + 2, pos, m, r);
	}
	void modify(int id, int ql, int qr, int l, int r, int v){
		push(id, l, r);
		if(ql >= r || l >= qr) return;
		//cout << "Running modi(" << id << ", " << ql << ", " << qr << ", " << l << ", " << r << ", " << v << ")\n";
		if(ql <= l && r <= qr){
			tag[id] |= v;
			push(id, l, r);
			return;
		}
		int m = (l + r) / 2;
		modify(2 * id + 1, ql, qr, l, m, v);
		modify(2 * id + 2, ql, qr, m, r, v);
		pull(id);
	}
} can;

inline bool check(int len){
	//cout << "Checking " << len << endl;
	multiset<int> st;
	int L, R, M, mx, mn, fs1, fs2, res;
	can = Seg();
	R = 1;
	for(L = 1; L <= N; L++){
		if(L > 1) st.erase(st.find(coords1[L - 1]));
		//cout << "JIZZ" << endl;
		if(R == L){
			st.insert(coords1[R++]);
		}
		//cout << "Min: " << *st.begin() << ", Max: " << *st.rbegin() << endl;
		maxGo[L] = L; 
		if(!(Abs(*st.begin() - coords1[L]) <= len && Abs(*st.rbegin() - coords1[L]) <= len)) continue;
		while(R <= N && Abs(*st.begin() - coords1[L]) <= len && Abs(*st.rbegin() - coords1[L]) <= len) st.insert(coords1[R++]);   
		if(!(Abs(*st.begin() - coords1[L]) <= len && Abs(*st.rbegin() - coords1[L]) <= len)) st.erase(st.find(coords1[--R]));
		maxGo[L] = R - 1;
		if(R == N + 1) break;
		//cout << "maxGo[" << L << "] = " << maxGo[L] << endl;
	}
	fs1 = fs2 = 0;
	mx = mn = coords1[0];
	for(int i = 1; i <= N; i++){
		mx = max(mx, coords1[i]);
		mn = min(mn, coords1[i]);
		if(mx > coords1[0] + len || mn < coords1[0] - len){
			fs1 = i - 1;
			break;
		} else if(i == N) fs1 = N; 
	}
	mx = mn = coords2[0];
	for(int i = 1; i <= N; i++){
		mx = max(mx, coords1[i]);
		mn = min(mn, coords1[i]);
		if(mx > coords2[0] + len || mn < coords2[0] - len){
			fs2 = i - 1;
			break;
		} else if(i == N) fs2 = N; 
	}
	can.modify(0, 0, fs1 + 1, 0, N + 1, 2);
	can.modify(0, 0, fs2 + 1, 0, N + 1, 1);
	//cout << "fs1 = " << fs1 << ", fs2 = " << fs2 << endl;
	for(int i = 1; i <= N; i++){
		if(maxGo[i] <= i) continue;
		if(can.query(0, i, 0, N + 1) & 1){
			//cout << "JIZZHI" << endl;
			can.modify(0, i, maxGo[i] + 1, 0, N + 1, 2);
		}
		if(can.query(0, i, 0, N + 1) & 2){
			can.modify(0, i, maxGo[i] + 1, 0, N + 1, 1);
		}
	}
	return (can.query(0, N, 0, N + 1) > 0);
}

signed main(){
	Read(N);
	Read(coords1[0]);
	Read(coords2[0]);
	for(int i = 1; i <= N; i++){
		Read(coords1[i]);
		coords2[i] = coords1[i];
	}
	int l = Abs(coords1[0] - coords2[0]) - 1, r = 1e9 + 10, m; 
	while(l + 1 < r){
		m = (l + r) / 2;
		//cout << "m = " << m << endl;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	printf("%d\n", r);
}

