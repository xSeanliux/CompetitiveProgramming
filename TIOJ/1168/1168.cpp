#pragma g++ optimize ("O3, avx2, loop_opt(on), unroll-loops, avx512, sse2")
#include <queue>
#include "lib1168.h"
using namespace std;

const int maxN = 5e5 + 1;
int szL = 0, szS = 0, cnt = 0;

struct Node{
	int F, S;
	Node(){}
	Node(int a, int b): F(a), S(b){}
	const bool operator<(const Node &n) const{
		return F < n.F;
	}
} pqs[maxN], pql[maxN];

unsigned char isOut[maxN];

void pop_big(){
	while(isOut[pql[0].S]){
		pop_heap(pql, pql + szL);
		--szL;
	}
	isOut[pql[0].S] = true;
}

void pop_small(){
	while(isOut[pqs[0].S]){
		pop_heap(pqs, pqs + szS);
		--szS;
	}
	isOut[pqs[0].S] = true;
}

void push(int s){
	pqs[szS] = {-s, cnt};
	pql[szL] = {s, cnt};
	++cnt;
	++szL, ++szS;
	push_heap(pqs, pqs + szS);
	push_heap(pql, pql + szL);
	if(__builtin_expect((szL > 500001), 0)) szL = 500000;
	if(__builtin_expect((szS > 500001), 0)) szS = 500000;
}

int big(){
	while(isOut[pql[0].S]){
		pop_heap(pql, pql + szL);
		--szL;
	}
	return pql[0].F;
}

int small(){
	while(isOut[pqs[0].S]){
		pop_heap(pqs, pqs + szS);
		--szS;
	}
	return -pqs[0].F;
}

