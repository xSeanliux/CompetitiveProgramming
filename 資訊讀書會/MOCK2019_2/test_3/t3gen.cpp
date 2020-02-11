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
string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/資訊讀書會/MOCK2019_2/test_3";
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ofstream myfile;
    for(int k = 9; k <= 11; k++){
        myfile.open (s + "/" + to_string(k) + ".in");
        int N = rnd.next(2000, 5000);
        myfile << N << '\n';
        int x, y;
        set<pii> st;
        set<int> xes;
        while(st.size() < N){
            do{
                x = rnd.next(1, (int)1e4);
                y = rnd.next(1, (int)1e4);
            } while(st.count({x, y}));
            st.insert({x, y});
            cout << "x = " << x << ", y = " << y << endl;
            xes.insert(x);
        }
        vector<pii> vec;
        for(auto p : st) vec.push_back(p);
        shuffle(vec.begin(), vec.end());
        for(auto p : vec) myfile << p.F << " " << p.S << '\n';
        cout << xes.size() << "Distinct X-Values" << endl;
        int Q = rnd.next((int)min(7500, 10000 - (int)xes.size()), 10000 - (int)xes.size());
        myfile << Q << '\n';
        int qq;
        for(int i = 0; i < Q; i++){
            do{
                qq = rnd.next(1, 10000);
            } while(xes.count(qq));
            myfile << qq << '\n';
        }
        myfile.close();
    }

}
