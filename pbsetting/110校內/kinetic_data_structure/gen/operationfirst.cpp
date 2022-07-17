#include "testlib.h"
#include <cassert>
using namespace std;
//is a random generator.

const int maxC = 1e9;

int main(int argc, char* argv[]) {
    assert(argc > 2);
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int Q = atoi(argv[2]);
    cout << N << " " << Q << endl;
    for(int i = 0; i < N; i++) cout << rnd.next(0, maxC) << " \n"[i == N - 1];
    for(int i = 0; i < N; i++) cout << rnd.next(0, maxC) << " \n"[i == N - 1];
    for(int i = 0; i < Q; i++){
    	int c = (i < Q / 2 ? rnd.next(1, 2) : 3), l = rnd.next(1, N), r = rnd.next(l, N);
    	cout << c << " " << l << " " << r;
    	if(c <= 2) cout << " " << rnd.next(0, maxC);
    	cout << endl;
    }
}
