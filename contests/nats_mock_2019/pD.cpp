#include "Land.h"
#define INF = 1e9

int gcd(long long int a, long long int b){
	return !b ? a : gcd(b, a % b);
}

rectangle find_rectangle(int subtask){
	int l = 0, r = INF + 1, u = INF + 1, d = 0, m, res;
	int allarea = area(0, 0, INF, INF);
	while(l + 1 < r){
		m = (l + r) / 2;
		res = area(0, 0, m, INF);
		if(!res) l = m;
		else if(res == allarea) r = m;
		else break;
	}
	if(l + 1 < r){
		//x: l - m have area res, m + 1 ~ r has area allarea - res
		int lft = res, rgt = allarea - res, g = gcd(lft, rgt);
		lft /= g; 
		rgt /= g;
		int newl = l, newr = m, newm, nres;
		while(newl + 1 < newr){
			newm = (newl + newr) / 2;
			nres = area(newm, 0, m, INF); 
			if(nres < res){
				newr = newm;
			} else {
				newl = newm;
			}
		}
		//left edge is at newl 
		r = (m - newl) * rgt / lft + m;
		l = newm;
	}
	while(d + 1 < u){
		m = (d + u) / 2;
		res = area(0, 0, INF, m);
		if(!res) d = m;
		else if(res == allarea) u = m;
		else break;
	}
	if(d + 1 < u){
		int dwn = res, up = allarea - res, g = gcd(dwn, up);
		dwn /= g; 
		up /= g;
		int newu = u, newd = m, newm, nres;
		while(newd + 1 < newu){
			newm = (newu + newd) / 2;
			nres = area(0, m, INF, newm);
			if(nres == up) newu = newm;
			else newd = newm;
		}
		d = m - (newu - m) * dwn / up;
		u = newu;
	}
	rectangle Rect;
	Rect.a = l;
	Rect.b = d;
	Rect.c = r;
	Rect.d = u;
	return Rect;
}
