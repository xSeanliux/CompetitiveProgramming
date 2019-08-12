#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = rnd.next(1, 5000);
    int K = rnd.next(1, N);
    cout << N << " " << K << endl;
    for(int i = 0; i < N; i++){
        cout << rnd.next(1, 1000000) << " \n"[i == N - 1];
    }
}
