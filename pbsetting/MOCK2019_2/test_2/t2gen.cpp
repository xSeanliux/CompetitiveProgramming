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
string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/資訊讀書會/MOCK2019_2/test_2";
int main(int argc, char* argv[])
{
        int N = rnd.next(75, 100);
        cout << N << '\n';
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
        for(auto p : vec) cout << p.F << " " << p.S << '\n';
        int Q = rnd.next(50, 100);
        cout << Q << '\n';
        for(int i = 0; i < Q; i++){
            cout << rnd.next(1, (int)(1e4)) << '\n';
        }
    /*
    registerGen(argc, argv, 1);
    ofstream myfile;
    for(int k = 4; k <= 8; k++){
        myfile.open (s + "/" + to_string(k) + ".in");
        int N = rnd.next(75, 100);
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
        int Q = rnd.next(50, 100);
        myfile << Q << '\n';
        for(int i = 0; i < Q; i++){
            myfile << rnd.next(1, (int)(1e4)) << '\n';
        }
        myfile.close();
    }
    */

}
