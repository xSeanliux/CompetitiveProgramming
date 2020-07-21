#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include "testlib.h"
using namespace std;
string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/xor_shortest/test_4/", dir;

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
	for(int test = 31; test <= 40; test++){
		cout << "Doing t = " << test << endl;	

		vector<Edge>().swap(edges);
		dir = _dir + to_string(test) + ".in";
		outfile.open(dir);

		N = rnd.wnext(maxN, 4); 
		M = 0;
		int s = rnd.next(1, N);
		int t = rnd.next(1, N);
		for(int i = 1; i <= N; i++){
			for(int j = i + 1; j <= N; j++){
				if(rnd.next(1000.0) <= p * 1000){ //there is an edge!
					y = rnd.next(maxW + 1);
					x = rnd.next(maxC);
					edges.push_back(Edge(i, j, x, y));
					M++;
				}
			}
		}
		//shuffle(edges.begin(), edges.end());
		outfile << N << " " << M << " " << s << " " << t << endl;
		cout << N << " " << M << " " << s << " " << t << endl;
		for(Edge e : edges){
			outfile << e.u << " " << e.v << " " << e.x << " " << e.y << endl;	
			//cout << e.u << " " << e.v << " " << e.x << " " << e.y << endl;
		}
		outfile.close();

	}
}

