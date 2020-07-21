#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include "testlib.h"
using namespace std;
string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/xor_shortest/test_3/", dir;

const int maxN = 1000;
const int maxM = 5000, maxC = 1024, maxW = 1e9;
const double p = 0.0095;
int seed = 101;

struct Edge{
	int u, v, x, y;
	Edge(int u, int v, int x, int y): u(u), v(v), x(x), y(y){}
};

vector<Edge> edges;

int N, M, a, b, x, y, s, t;

ofstream outfile; 

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	dir = _dir + to_string(30) + ".in";
	outfile.open(dir);
	outfile << "1000 999 6 12" << endl;
	for(int i = 2; i <= 1000; i++){
		if(i == 6 || i == 12) continue;
		outfile << i << " " << 1 << " " << rnd.next(maxC) << " " << rnd.next(maxW + 1) << endl;
	}
	outfile << "6 1 123123 98" << endl;
	outfile << "1 12 123123 222128" << endl;
}

