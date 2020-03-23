#include <iostream>
#include "xylophone.h"
using namespace std;

const int maxN = 6e3 + 226;

int val[maxN], q1[maxN], q2[maxN], a, b, c, minAt, maxAt, ans[maxN];

void solve(int N){
	int a, b, c;
	for(int i = 1; i < N; i++){
		q1[i] = query(i, i + 1);
	}
	for(int i = 1; i < N - 1; i++){
		q2[i] = query(i, i + 2);
	}
	val[2] = q1[1];
	for(int i = 3; i <= N; i++){
		a = q1[i - 2], b = q1[i - 1], c = q2[i - 2];
		if(a + b == c){
			if(val[i - 1] > 0) val[i] = b;
			else val[i] = -b;
		} else {
			if(val[i - 1] > 0) val[i] = -b;
			else val[i] = b;
		}
	}
	minAt = maxAt = 1;
	for(int i = 1; i <= N; i++){
		ans[i] = val[i] + ans[i - 1];
		if(ans[minAt] > ans[i]) minAt = i;
		if(ans[maxAt] < ans[i]) maxAt = i;
	}
	if(minAt < maxAt){
		for(int i = 1; i <= N; i++) answer(i, ans[i] - ans[minAt] + 1);
		return;
	}
	minAt = maxAt = 1;
	for(int i = 1; i <= N; i++){
		ans[i] = -val[i] + ans[i - 1];
		if(ans[minAt] > ans[i]) minAt = i;
		if(ans[maxAt] < ans[i]) maxAt = i;
	}
	for(int i = 1; i <= N; i++) answer(i, ans[i] - ans[minAt] + 1);
}
