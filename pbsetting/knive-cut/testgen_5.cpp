/*
 * Outputs random number between 1 and 10^6, inclusive.
 * To generate different values, call "igen.exe" with different parameters.
 * For example, "igen.exe 1" returns 504077, but "igen.exe 3" returns 808747.
 *
 * It is typical behaviour of testlib generator to setup randseed by command line.
 */

#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[])
{
    vector<long long int> v;
    registerGen(argc, argv, 1);
    int N = rnd.next(1, 500), K = rnd.next(1, 20);
    while(K > N) K = rnd.next(1, 20);
    cout << N << " " << K << endl;
    for(int i = 0; i < N; i++){
        v.push_back(rnd.next(-1000000000, 1000000000));
    }
    for(int i = 0; i < N; i++) cout << v[i] << " \n"[i == N - 1];
    return 0;
}




