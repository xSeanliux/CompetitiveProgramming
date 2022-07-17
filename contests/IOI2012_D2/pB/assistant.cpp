#include <iostream>
#include <set>
#include <utility>
#include <queue>
#include <cassert>
#define pii pair<int,int>
#define F first
#define S second
#include "assistant.h"
using namespace std;


bool cur[101010], inq[101010];
queue<int> que;

void Assist(unsigned char *A, int N, int K, int R) {
	//assert(R == N + K);	
	for(int i = 0; i < K; i++){
		cur[i] = true;
		if(A[i]) que.push(i);
	}
	//int bc = 0, key;
	//while((1 << bc) < N + 1) bc++;
	for(int i = 0; i < N; i++){
		int r = GetRequest();	
		if(!cur[r]){
			int c = que.front(); que.pop();
			cur[c] = false;
			PutBack(c);
		} 
		cur[r] = true;
		if(A[i + K]) que.push(r);
	}
}
