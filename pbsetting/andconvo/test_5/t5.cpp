#include "testlib.h"
#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
using namespace std;

string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/andconvo/test_5";

/*
Last Case
*/

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ofstream myfile;
    for(int k = 25; k <= 34; k++){
        myfile.open (s + "/" + to_string(k) + ".in");
        int N = rnd.next(75000, 100000), K = rnd.next(15, 20);
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
