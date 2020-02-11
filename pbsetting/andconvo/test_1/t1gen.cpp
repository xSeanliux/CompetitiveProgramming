#include "testlib.h"
#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
using namespace std;

const int maxN = 1e4;
string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/andconvo/test_1";

/*
Test 1:
3 cases
N <= 1
K no restrictions
*/

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ofstream myfile;
    for(int k = 2; k <= 3; k++){
        myfile.open (s + "/" + to_string(k) + ".in");
        int N = 0, K = rnd.next(3, 20);
        myfile << N << " " << K << endl;
        for(int i = 0; i < N; i++){
            myfile << rnd.next(0, (1 << K) - 1) << " \n"[i == N - 1];
        }
        for(int i = 0; i < N; i++){
            myfile << rnd.next(0, (1 << K) - 1) << " \n"[i == N - 1];
        }
        myfile.close();
    }

}
