#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include "testlib.h"
using namespace std;
string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/109校內初賽/circdraw/alltest/", dir;


ofstream outfile;

const int maxN = 1000, startt = 0, endt = 5, maxC = 1e9;
int seed = 101, N;

void writeTest(int testnum){
	cout << "Writing: " << testnum << endl;
	dir = _dir + to_string(testnum) + ".in";
	cout << "dir = " << dir << endl;
	outfile.open(dir);	

	N = rnd.wnext(1, maxN, 3);
	outfile << N << endl;
	for(int i = 0; i < N; i++){
		outfile << rnd.next(-maxC, maxC) << " " << rnd.next(-maxC, maxC) << endl;
	}
	outfile.close();	
}

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	for(int t = startt; t <= endt; t++){
		writeTest(t);
	}
}

