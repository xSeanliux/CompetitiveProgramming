#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include "testlib.h"
using namespace std;
string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/109校內初賽/eatspice/test_1/", dir;



const int maxN = 200000, startt = 6, endt = 8, maxC = 1e5;
int seed = 101;

int N, L;
vector<int> v;
set<int> st;

ofstream outfile; 

void writeTest(int testnum){
	cout << "Writing: " << testnum << endl;
	dir = _dir + to_string(testnum) + ".in";
	cout << "dir = " << dir << endl;
	outfile.open(dir);	
	N = rnd.wnext(1, maxN, 3);
	N = maxN;
	L = rnd.next(1, 1);
	vector<int> stuff;
	for(int i = 0; i < 2 * N; i++) stuff.push_back(rnd.next(1, maxC));
	outfile << N << " " << L << endl;
	for(int i = 0; i < 2 * N; i++){
		outfile << stuff[i] << " \n"[(i % N) == N - 1];	
	}
	outfile.close();
}

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	for(int t = startt; t <= endt; t++){
		writeTest(t);
	}
}

