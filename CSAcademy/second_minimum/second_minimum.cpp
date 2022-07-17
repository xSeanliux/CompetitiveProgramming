#include <iostream>

using namespace std;
const int maxN = 1e4 + 326;
int seg[maxN << 2], N;

int ask(int a, int b){
	if(a == b) return a;
	int x;
	cout << "Q " << a << " " << b << endl;
	cin >> x;
	return x;
}

void build(int id = 0, int l = 1, int r = N + 1){
    if(l + 1 == r){
        seg[id] = l;
        return;
    }
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	seg[id] = ask(seg[2 * id + 1], seg[2 * id + 2]);
}

int query(int id, int ql, int qr, int l, int r){
	if(ql >= r || l >= qr) return ql;
	if(ql <= l && r <= qr) return seg[id];
	int m = (l + r) / 2;
	return ask(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
}

void modify(int id, int l, int r, int p, int v){
	if(l + 1 == r){
		seg[id] = v;
		return;
	}
	int m = (l + r) / 2;
	if(p < m) modify(2 * id + 1, l, m, p, v);
	else modify(2 * id + 2, m, r, p, v);
	seg[id] = ask(seg[2 * id + 1], seg[2 * id + 2]);
}

int main() {
	cin >> N;
	build();
	int oneAt = seg[0], a, b;
	modify(0, 1, N + 1, oneAt, (oneAt == 1) + 1);
	cout << "A " << seg[0] << endl;
}
