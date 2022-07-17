#include <iostream>
#include <cassert>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;

struct Rect{
	int l, r, d, u, A;
	Rect(){}
	Rect(int l, int r, int d, int u): l(l), r(r), d(d), u(u){
		A = (r - l + 1) * (u - d + 1);
	}
} rects[maxN];

inline bool onDiag(int x, int y, int d){
	return	(((x % (2 * d)) < d) == ((y % (2 * d)) < d)); 
}

inline int id(int x, int y, int d){
	return x / d * maxN + y / d;		
}

inline int getArea(int a, int b){
	if(a < 0 || b < 0) return 0;
	return a * b;
}

inline int Area(int l, int r, int d, int u, int div){
	if(l > r || d > u) return 0;
	if(div == 1){
		if(((r - l + 1) & 1) && ((u - d + 1) & 1) && onDiag(l, u, div)) return ((r - l + 1) * (u - d + 1) + 1)/ 2;
		return ((r - l + 1) * (u - d + 1))/ 2;
	}
	//cout << "running: " << l << " " << r << " " << d << " " << u << " " << div << endl;
	int _l = (l + div - 1) / div * div, _r = r / div * div, _u = u / div * div, _d = (d + div - 1) / div * div, res = 0;
	if((l / div == r / div) && (u / div == d / div)){
		return (u - d + 1) * (r - l + 1) * onDiag(l, u, div);
	}
	if(l / div == r / div){
		//cout << "u = " << u << ", _u = " << _u << ", d = " << d << ", _d = " << _d << endl;
		int k = 0;
		k += (u - _u + 1) * onDiag(l, u, div);
		k += (_d - d) * onDiag(l, d, div);
		if(onDiag(l, _d, div) && ((_u - _d) / div) & 1) k += ((_u - _d) / div / 2 + 1) * div;
		else k += ((_u - _d) / div / 2) * div; 
		return k * (r - l + 1);
	} 
	if(u / div == d / div){
		int k = 0;
		k += (_l - l) * onDiag(l, u, div);
		k += (r - _r + 1) * onDiag(r, u, div);
		if(onDiag(_l, u, div) && ((_r - _l) / div) & 1) k += ((_r - _l) / div / 2 + 1) * div;
		else k += ((_r - _l) / div / 2) * div; 
		return k * (u - d + 1);
	}
	res = (_r - _l) / div * (_u - _d) / div;
	if(onDiag(_l, _d, div) && (res & 1)) res = (res + 1) / 2; 
	else res = res / 2;
	res *= div * div;
	if(onDiag(l, u, div)){
		res += getArea((_l - l), (u - _u + 1));
	} 
	if(onDiag(r, u, div)){
		res += getArea((r - _r + 1), (u - _u + 1));
	} 
	if(onDiag(r, d, div)){
		res += getArea((r - _r + 1), (_d - d));
	}	
	if(onDiag(l, d, div)){
		res += getArea((_l - l), (_d - d));
	} 
	res += Area(_l, _r - 1, _u, u, div);
	res += Area(_l, _r - 1, d, _d - 1, div);
	res += Area(l, _l - 1, _d, _u - 1, div);
	res += Area(_r, r, _d, _u - 1, div);
	//cout <<  l << " " << r << " " << d << " " << u << " " << div << ", res = " << res << endl;
	return res;
}

int N, K;

inline int check(int d){
	//top left is black
	//cout << "d = " << d << endl;
	int _ans = maxN * maxN, tmp = ((N / d) * (N / d) + 1) / 2 * (d * d), tmp2 = ((N / d) * (N / d)) / 2 * (d * d);
	//cout << "1tmp = " << tmp << endl;
	for(int i = 0; i < K; i++){
		int A = Area(rects[i].l, rects[i].r, rects[i].d, rects[i].u, d), B = rects[i].A - A;
		//cout << "d = " << d << ",A = " << A << endl;
		tmp += B - A;
		tmp2 += A - B;
	}
	//cout << "d: " << min(tmp, tmp2) << endl;
	return min(tmp, tmp2);
	//top right is black
}

signed main(){
	ericxiao;
	cin >> N >> K;
	int l, r, d, u;
	for(int i = 0; i < K; i++){
		cin >> l >> d >> r >> u;
		l--; d--; r--; u--;
		rects[i] = Rect(l, r, d, u);
		//cout << "rects[i] a = " << rects[i].A << endl;
	}
	int ans = maxN * maxN;
	for(int div = 1; div * div <= N; div++){
		if(!(N % div)){
			ans = min(ans, check(div));
			if(div != 1) ans = min(ans, check(N / div));
		}
	}
	cout << ans << endl;
}

/*
 * 
6 8
3 3 3 3
1 2 1 2
3 4 3 4
5 5 5 5
4 3 4 3
4 4 4 4
2 1 2 1
3 6 3 6
*/
