#include <iostream>
#define int long long int 
using namespace std;

inline int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) == 0) return r;
		if((e >> i) & 1) r = r * b;
		b = b * b;
	}
	return r;
}

inline int Abs(int x){
	return x < 0 ? -x : x;
}

signed __D;
int D, ans, bases[20], baselim[20];
int solve(int now, int dif, int lim){
	if(now == lim) return (dif == 0);  
	int r = 0;
	for(int d = -9; d < 10; d++){
		if(Abs(d * bases[now] - dif) <= baselim[now + 1]){
			//cout << "d = " << d << endl;
			//cout << "affect: " << d * bases[now] << endl;
			//count how many there can be
			int pos = 0;
			for(int a = 0; a < 10; a++){
				//cout << "a = " << a << endl;
				if(0 <= (a - d) && (a - d) < 10){
					if(!now) pos += (a != 0 && ((a - d) != 0));
					else pos++;
				}
			}
			r += pos * solve(now + 1, dif - d * bases[now], lim);
		}
	}
	return r;
}

signed main(){
	cin >> __D;
	D = __D;
	int d;
	for(d = 2; d < 19; d++){		
		int h =  exp(10, d) - exp(10, (d + 1) / 2) + 1;
		int r =  exp(10, d - 1) + exp(10, (d) / 2) - 1;
		//cout << "d = " << d << endl;
		int _ans = 1;
		for(int i = 0; i < d / 2; i++){
			bases[i] = exp(10, d - i - 1) - exp(10, i);
			//cout << "base["<<i<<"] = " << bases[i]<<endl;
		}
		for(int i = d / 2 - 1; i >= 0; i--){
			baselim[i] = 9 * bases[i] + baselim[i + 1];
		}
		//for(int i = 0; i < d / 2; i++) cout << baselim[i] << " ";
		//cout << endl;
		_ans = solve(0, D, d / 2);
		if(d & 1) _ans *= 10;
		ans += _ans;
	}
	//cout << "d = " << d << endl;
	
	cout << (signed)ans << endl;
	//cout << "d = " << d << endl;
}


