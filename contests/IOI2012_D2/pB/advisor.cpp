#include "advisor.h"
#include <iostream>
#include <utility>
#include <cassert>
#include <set>
#include <deque>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

struct Obj{
	int time, col;
	Obj(int time = 0, int col = 0): time(time), col(col){}
	const bool operator<(const Obj &o) const {
		return col == o.col ? time < o.time : col < o.col;
	}
};

const int maxN = 1e5 + 326;
bool has[maxN], advice[maxN << 1];
set <pair<int, Obj>> st;
deque<int> dq[maxN];


void ComputeAdvice(int *C, int N, int K, int M) {
	fill(has, has + K, 1);
	for(int i = 0; i < N; i++){
		dq[C[i]].push_back(i);
	}
	for(int i = 0; i < K; i++){
		int furt = dq[i].size() ? dq[i].front() : maxN;
		st.insert({furt, Obj(i - K, i)});
	}
	//int bc = 0, key;
	//while((1 << bc) < N + 1) bc++;
	for(int i = 0; i < N; i++){ //thirteen bits lol
		//key = -1;
		if(has[C[i]]){
			int furt = dq[C[i]].size() ? dq[C[i]].front() : maxN;
			st.erase(st.lower_bound({furt, Obj(-maxN, C[i])}));
		} else {
			auto it = --st.end();
			advice[it->S.time + K] = 1;
			st.erase(st.find({it->F, it->S}));
			has[it->S.col] = false;
			//key = it->S.col;
		}
		//if(key == -1) key = (1 << bc) - 1;
		while(dq[C[i]].size() && dq[C[i]].front() <= i) dq[C[i]].pop_front();
		int furt = dq[C[i]].size() ? dq[C[i]].front() : maxN;
		st.insert({furt, Obj(i, C[i])});
		has[C[i]] = true;
		//for(int j = 0; j < bc; j++) WriteAdvice((key >> j) & 1);
	}
	for(int i = 0; i < N + K; i++) WriteAdvice(advice[i]);
}

