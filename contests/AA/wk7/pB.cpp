#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
struct Frac{
	int a, b;
	Frac(int _a = 1, int _b = 1): a(_a), b(_b){
		if(b == 0){
			a = 1;
		} else if(a == 0){
			b = 1;
		} else {
			int g = gcd(a, b);
			//cout << "gcd(" << a << ", " << b << ") = " << g << endl;
			a /= g;
			b /= g;
		}
		if(a * b < 0 && a < 0){
			a = -a; b = -b;
		}
	}
};
inline const Frac operator+(Frac x, Frac y){
	return Frac(x.a * y.b + x.b * y.a, x.b * y.b);
}
inline const Frac operator-(Frac x, Frac y){
	return Frac(x.a * y.b - x.b * y.a, x.b * y.b);
}
inline const Frac operator*(Frac x, Frac y){
	return Frac(x.a * y.a, x.b * y.b);
}
inline const Frac operator/(Frac x, Frac y){
	return Frac(x.a * y.b, x.b * y.a);
}
inline const Frac operator==(Frac x, Frac y){
	return x.a * y.b < y.a * x.b;
}
inline const Frac operator<(Frac x, Frac y){
	bool sgn = (x.b < 0) ^ (y.b < 0);
	return (x.a * y.b < y.a * x.b) ^ sgn;
}

void solve(){
	int ox, oy, vx, vy, ax, ay, bx, by;
	cin >> ox >> oy >> vx >> vy >> ax >> ay >> bx >> by;
	if(ax > bx){
		swap(ax, bx);
		swap(ay, by);
	}
	int M = (bx - ax) * vy - (by - ay) * vx, K = (by - ay) * (ox - ax) - (bx - ax) * (oy - ay);
	if(M == 0){
		if(K == 0){ //the same line
			if((vx * (ax - ox)) >= 0 && (vy * (ay - oy)) >= 0){
				if(vx * (ax - ox) == 0){
					cout << min((ay - oy) * 1.0 / vy, (by - oy) * 1.0 / vy) << endl;
				} else {
					cout << min((ax - ox) * 1.0 / vx, (bx - ox) * 1.0 / vx) << endl;
				}
			} else {
				cout << -1 << endl;
			}
		} else {
			cout << -1 << endl;
			return;
		}
	} else {
		if(bx != ax){
			Frac X = Frac(ox, 1) + (Frac(vx, 1) * Frac(K, M));
			//cout << "X = " << X.a << "/" << X.b << endl;
			Frac S = (X - Frac(ax, 1)) / (Frac(bx, 1) - Frac(ax, 1));
			//cout << S.a << "/" << S.b << endl;
			if(S.b > 0 && S.a <= S.b && K * M >= 0){
				cout << K * 1.0 / M << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
			Frac Y = Frac(oy, 1) + (Frac(vy, 1) * Frac(K, M));
			//cout << "Y = " << Y.a << "/" << Y.b << endl;
			Frac S = (Y - Frac(ay, 1)) / (Frac(by, 1) - Frac(ay, 1));
			//cout << S.a << "/" << S.b << endl;
			if(S.b > 0 && S.a <= S.b && K * M >= 0){
				cout << K * 1.0 / M << endl;
			} else {
				cout << -1 << endl;
			}
		}
	}
}
int main(){
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
