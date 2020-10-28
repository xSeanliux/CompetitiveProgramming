#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include "testlib.h"
using namespace std;
string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/weirdconvo/alltest/", dir;



const int maxN = 1e5, startt = 11, endt = 20, maxC = 1e9;
int seed = 101;

int N, M, K;
vector<int> a, b;

ofstream outfile; 

void writeTest(int testnum){
	cout << "Writing: " << testnum << endl;
	dir = _dir + to_string(testnum) + ".in";
	cout << "dir = " << dir << endl;
	outfile.open(dir);	

	vector<int>().swap(a);
	vector<int>().swap(b);
	N = rnd.next(1, maxN);
	for(int i = 0; i < N; i++){
		a.push_back(rnd.next(-1000, 1000));
		b.push_back(rnd.next(-1000, 1000));
	}
	outfile << N << endl;
	for(int x : a) outfile << x << " ";
	outfile << '\n';
	for(int x : b) outfile << x << " ";
	outfile << '\n';
	outfile.close();	
}

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	for(int t = startt; t <= endt; t++){
		writeTest(t);
	}
}

