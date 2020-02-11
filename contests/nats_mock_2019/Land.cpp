#include "Land.h"
#include <iostream>
using namespace std;
//----do not modify above----
#define INF 1e9

long long int gcd(long long int a, long long int b){
	return !b ? a : gcd(b, a % b);
}

rectangle find_rectangle(int subtask){
	long long int l = 0, r = INF + 1, u = INF + 1, d = 0, m, res;
	long long int allarea = area(0, 0, INF, INF);
	//cout << "Allarea = " << allarea << endl;
	while(l + 1 < r){
		m = (l + r) / 2;
		//cout << "Calling area(0, 0, " << m << ", INF)" << endl;
		res = area(0, 0, m, INF);
		if(!res) l = m;
		else if(res == allarea) r = m;
		else break;
	}

	if(l + 1 < r){
        //cout << "m = " << m << endl;
		//x: l - m have area res, m + 1 ~ r has area allarea - res
		long long int lft = res, rgt = allarea - res, g = gcd(lft, rgt);
		long long int newl = l, newr = m, newm, nres;
		while(newl + 1 < newr){
			newm = (newl + newr) / 2;
            //cout << "Calling area(" << newm << ", 0, " << m << ", INF)" << endl;
			nres = area(newm, 0, m, INF);
			if(nres < res){
				newr = newm;
			} else {
				newl = newm;
			}
		}
		lft /= g;
		rgt /= g;
		//left edge is at newl
		r = (m - newl) * rgt / lft + m;
		l = newl;
	}
	while(d + 1 < u){
		m = (d + u) / 2;
        res = area(0, 0, INF, m);
		if(!res) d = m;
		else if(res == allarea) u = m;
		else break;
	}
	//cout << "m = " << m << endl;
	if(d + 1 < u){
		long long int dwn = res, up = allarea - res, g = gcd(dwn, up);
		//cout << "up = " << up << endl;
		long long int newu = u, newd = m, newm, nres;
		while(newd + 1 < newu){
			newm = (newu + newd) / 2;
            //cout << "Calling area(0, " << m << ", INF, " << newm << ")" << endl;
			nres = area(0, m, INF, newm);
			//cout << "nres = " << nres << endl;
			if(nres == up) newu = newm;
			else newd = newm;
			//cout << "newu = " << newu << ", newd= " << newd << endl;
		}
		dwn /= g;
		up /= g;
		d = m - (newu - m) * dwn / up;
		u = newu;
	}
	rectangle Rect;
	Rect.a = (int)l;
	Rect.b = (int)d;
	Rect.c = (int)r;
	Rect.d = (int)u;
	return Rect;
}


//----do not modify below----

#ifndef EVAL
namespace{
	constexpr int _MAX_C = 1000000000;
	constexpr int _MAX_NUM_QUERY = 128;
	int _count=0,_a,_b,_c,_d;
	bool _valid(int x){
		if(x<0||x>_MAX_C) return 0;
		return 1;
	}
	int _max(int a,int b){
		if(a>b) return a;
		return b;
	}
	int _min(int a,int b){
		if(a<b) return a;
		return b;
	}
	void _input(int *x){
		scanf("%d",x);
	}
	void _wrong_answer(const char *MSG) {
		printf("Wrong Answer: %s\n", MSG);
		exit(0);
	}
	void _Accepted(const int c){
		printf("Accepted: %d\n",c);
	}
}

long long area(int x1, int y1, int x2, int y2){
	++_count;
	if(_count>_MAX_NUM_QUERY)
		_wrong_answer("too many queries");
	if(!_valid(x1)||!_valid(x2)||!_valid(y1)||!_valid(y2))
		_wrong_answer("invalid query");
	if(!(x1<x2&&y1<y2))
		_wrong_answer("invalid query");
	int ml=_max(x1,_a),mr=_min(x2,_c);
	int md=_max(y1,_b),mu=_min(y2,_d);
	if(ml>=mr||md>=mu) return 0;
	return (long long)(mr-ml)*(long long)(mu-md);
}

int main() {
	int t,mx=0,subtask=0;
	rectangle tmp;
	_input(&t),_input(&subtask);
	while(t--){
		_count=0;
		_input(&_a),_input(&_b),_input(&_c),_input(&_d);
		tmp=find_rectangle(subtask);
		if(tmp.a!=_a||tmp.b!=_b||tmp.c!=_c||tmp.d!=_d)
			_wrong_answer("incorrect place");
		else
			mx=_max(mx,_count);
	}
	_Accepted(mx);
}
#endif
