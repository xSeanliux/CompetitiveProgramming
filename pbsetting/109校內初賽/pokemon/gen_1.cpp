#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include "testlib.h"
using namespace std;
string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/109校內初賽/pokemon/alltest/", dir;



const int maxN = 500, startt = 0, endt = 10, maxC = 1e9;
int seed = 101;

int N, M, K;
vector<int> a, b;
set<int> st;

ofstream outfile; 

void writeTest(int testnum){
	cout << "Writing: " << testnum << endl;
	dir = _dir + to_string(testnum) + ".in";
	cout << "dir = " << dir << endl;
	outfile.open(dir);	

	vector<int>().swap(a);
	vector<int>().swap(b);
	st = set<int>();
	N = rnd.wnext(1, maxN, 4);
	M = rnd.wnext(1, maxN, 4);
	K = rnd.wnext(1, min(N, M), 2);
	while(st.size() < N + M) st.insert(rnd.next(1, maxC));
	int cnt = 0;
	outfile << N << " " << M << " " << K << "\n";
	
	for(int x : st){
		if(b.size() == M) a.push_back(x);
		else b.push_back(x);
	}
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

