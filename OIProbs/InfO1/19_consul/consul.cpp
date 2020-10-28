#include "grader.h"
#define min(a,b) ((a<b)?(a):(b))
int seed = 101;

inline int rnd(){
	return seed = (seed * 3 + 1) % 0xdefaced;
}


void solve(int N){
	for(int i = 0; i < min(30, (N / 2)); i++){
		int r = rnd() % N + 1;
		int v = kth(r);
		int c = cnt(v);
		//cout << "loc = " << r << ", val = " << v << ", cnt = " << c << endl;
		if(c > (N / 3)){
			say_answer(v);
			return;
		}
	}
	say_answer(-1);
}
