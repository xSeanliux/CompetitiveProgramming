#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 3e5 + 326;

int N, M, arr[maxN];

struct Obj{
	int mx, mn, val, tag;
	Obj(int mx = 0, int mn = 0, int val = 0): mx(mx), mn(mn), val(val), tag(0){}
	const Obj operator+(const Obj &o){
		return Obj(max(o.mx, mx), min(o.mn, mn), max(val, o.val));
	}
	inline void disp(){
		cout << "mx = " << mx << " mn = " << mn << " val = " << val << endl;
	}
} seg[maxN << 2];

void push(int id, int l, int r){
	if(!seg[id].tag) return;
	seg[id].mx += seg[id].tag;
	seg[id].mn += seg[id].tag;
	seg[id].val += seg[id].tag;
	if(r - l > 1){
		seg[2 * id + 1].tag += seg[id].tag;
		seg[2 * id + 2].tag += seg[id].tag;
	}
	seg[id].tag = 0;
}

void build(int id = 0, int l = 1, int r = N + 1){
	if(l + 1 == r){
		seg[id] = Obj(arr[l], arr[l], arr[l] + l - N);
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

void B(int id, int l, int r, int x, int b){
	push(id, l, r);
	if(seg[id].mx < x) return;
	if(seg[id].mn >= x){
		seg[id].tag += b;
		push(id, l, r);
		return;
	}
	int m = (l + r) / 2;
	B(2 * id + 1, l, m, x, b);
	B(2 * id + 2, m, r, x, b);	
	seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

void K(int id, int l, int r, int x, int b){
	push(id, l, r);
	if(seg[id].mn > x) return;
	if(seg[id].mx <= x){
		seg[id].tag += b;
		push(id, l, r);
		return;
	}
	int m = (l + r) / 2;
	K(2 * id + 1, l, m, x, b);
	K(2 * id + 2, m, r, x, b);	
	seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

int count(int id, int l, int r, int val){ //how many numbers are >= val
	push(id, l, r);
	if(r - l == 1){
		return seg[id].mx >= val;
	}
	if(seg[id].mn >= val) return (r - l); 
	if(seg[id].mx < val) return 0; 
	int m = (l + r) / 2;
	return count(2 * id + 1, l, m, val) + count(2 * id + 2, m, r, val);
}

void segdisp(int id = 0, int l = 1 , int r = N + 1){
	push(id, l, r);
	if(r - l == 1){
		cout << l << ": "; seg[id].disp();
		return;
	}
	int m = (l + r) / 2;
	segdisp(2 * id + 1, l, m);
	segdisp(2 * id + 2, m, r);
}
char com;
int x, y;

signed main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++)	cin >> arr[i];
	sort(arr + 1, arr + 1 + N);
	reverse(arr + 1, arr + 1 + N);
	build();
	//segdisp();
	for(int i = 0; i < M; i++){
		cin >> com;
		if(com == 'B'){
			cin >> x >> y;
			B(0, 1, N + 1, x, y);
		} else if(com == 'K'){
			cin >> x >> y;
			K(0, 1, N + 1, x, -y);
		} else {
			push(0, 1, N + 1);
			cout << count(0, 1, N + 1, seg[0].val) << endl;
		}
		//segdisp();
	}
}
