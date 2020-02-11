#include "testlib.h"
#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
using namespace std;

const int maxN = 1e4;
string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/資訊讀書會/MOCK2019_2/test_1";
int main(int argc, char* argv[])
{
    ofstream myfile;
    for(int k = 1; k <= 3; k++){
        myfile.open (s + "/" + to_string(k) + ".in");
        registerGen(argc, argv, 1);
        myfile << 2 << endl;
        int x1 = rnd.next(0, maxN), y1 = rnd.next(0, maxN), x2 = rnd.next(0, maxN), y2 = rnd.next(0, maxN);
        while(x1 == x2 && y1 == y2){
            x1 = rnd.next(0, maxN);
        }
        myfile << x1 << " " << y1 << endl;
        myfile << x2 << " " << y2 << endl;
        vector<int> vals;
        for(int i = max(1, x1 - 1); i <= min(x1 + 1, maxN); i++) vals.push_back(i);
        for(int i = max(1, x2 - 1); i <= min(x2 + 1, maxN); i++) vals.push_back(i);
        myfile << vals.size() << endl;
        for(int x : vals) myfile << x << endl;
        myfile.close();
    }

}
