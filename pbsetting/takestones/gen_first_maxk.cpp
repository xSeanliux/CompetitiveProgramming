#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = 10;
    int K = 5;
    cout << N << " " << K << endl;
    for(int i = 0; i < N; i++){
        cout << rnd.next(-1000000000, 1000000000) << " \n"[i == N - 1];
    }
}


