#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include "testlib.h"
using namespace std;
string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/uniqsubstr/alltest/", dir;



const int maxN = 100000, startt = 11, endt = 15, maxC = 1e9;
int seed = 101;

int N, M, K;
vector<int> a, b;

ofstream outfile; 

/*
 * 0 - 2: Small tests
 * 3 - 7: Random test cases 
 * 8 - 10: Big test cases
 */ 

void writeTest(int testnum){
	cout << "Writing: " << testnum << endl;
	dir = _dir + to_string(testnum) + ".in";
	cout << "dir = " << dir << endl;
	outfile.open(dir);	
	/*
	int curc = 0, N = rnd.next(1, 3000);
	for(int i = 0; i < N; i++){
		int l = rnd.next(1, (int)(100000 - curc - (N - i - 1)));
		curc += l;
		string s = "";
		while(l--){
			s += (char)(rnd.next(0, 25) + 'a');
		}
		outfile << s << '\n';
	}
	*/
	for(int i = 0; i < 2e5; i++) outfile << (char)(rnd.next(0, 25) + 'a');
	cout << '\n';
	outfile.close();
}

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	for(int t = startt; t <= endt; t++){
		writeTest(t);
	}
}

