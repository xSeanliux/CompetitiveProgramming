#include "testlib.h"
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <ostream>
#define vv vector<vector<int> >
#define int long long int
using namespace std;

string dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/APCSCamp/a-plus-b/testcases";
ifstream infile;
ofstream outfile;

void solve(){
    int a, b;
    infile >> a >> b;
    outfile << (a + b) << endl;
}

void gen(){
    outfile << rnd.next((int)(-1e18), (int)(1e18)) << " " << rnd.next((int)(-1e18), (int)(1e18)) << endl;
}

signed main(signed argc, char* argv[]){
    registerGen(argc, argv, 1);
	for(int tc = 1; tc <= 10; tc++){
        cout << dir + "/" + to_string(tc) << endl;
        outfile.open(dir + "/" + to_string(tc) + ".in");	
        gen();
        outfile.close();

        infile.open(dir + "/" + to_string(tc) + ".in");	
        outfile.open(dir + "/" + to_string(tc) + ".out");	
        solve();
        infile.close();
        outfile.close();
	}
}

