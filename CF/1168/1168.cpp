#pragma gcc optimize ("Ofast")
#pragma loop_opt(on)
#include "lib1168.h"
#include <utility>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 5e5 + 326;
int szL = 0, szS = 0, cnt = 0;

pii pqs[maxN], pql[maxN];

bool isOut[maxN];

void pop_big(){
	while(isOut[pql[0].S]){
		pop_heap(pql, pql + szL);
		szL--;
	}
	isOut[pql[0].S] = true;
	pop_heap(pql, pql + szL);
	szL--;
}

void pop_small(){
	while(isOut[pqs[0].S]){
		pop_heap(pqs, pqs + szS, greater<pii>());
		szS--;
	}
	isOut[pqs[0].S] = true;
	pop_heap(pqs, pqs + szS, greater<pii>());
	szS--;
}

void push(int s){
	pqs[szS] = {s, cnt};
	pql[szL] = {s, cnt};
	cnt++;
	szL++, szS++;
	push_heap(pqs, pqs + szS, greater<pii>());
	push_heap(pql, pql + szL);
	szL = szL < 500001 ? szL : 500001;
	szS = szS < 500001 ? szS : 500001;
}

int big(){
	while(isOut[pql[0].S]){
		pop_heap(pql, pql + szL);
		szL--;
	}
	return pql[0].F;
}

int small(){
	while(isOut[pqs[0].S]){
		pop_heap(pqs, pqs + szS, greater<pii>());
		szS--;
	}
	return pqs[0].F;
}
