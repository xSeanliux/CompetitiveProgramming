#include "testlib.h"
#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
#include <set>
#define pii pair<int,int>
#include <algorithm>
#define F first
#define S second
using namespace std;

const int maxN = 1e4;
string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/資訊讀書會/MOCK2019_2/test_5";
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ofstream myfile;
    for(int k = 19; k <= 23; k++){
        myfile.open (s + "/" + to_string(k) + ".in");
        int N = rnd.next(8000000, 10000000);
        myfile << N << '\n';
        int x, y;
        set<pii> st;
        while(st.size() < N){
            do{
                x = rnd.next(1, (int)1e4);
                y = rnd.next(1, (int)1e4);
            } while(st.count({x, y}));
            st.insert({x, y});
        }
        vector<pii> vec;
        for(auto p : st) vec.push_back(p);
        shuffle(vec.begin(), vec.end());
        for(auto p : vec) myfile << p.F << " " << p.S << '\n';
        int Q = rnd.next(9000, 10000);
        myfile << Q << '\n';
        for(int i = 0; i < Q; i++){
            myfile << rnd.next(1, (int)(1e4)) << '\n';
        }
        myfile.close();
    }

}
