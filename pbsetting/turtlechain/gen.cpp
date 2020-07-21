#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <random>
#include "testlib.h"
using namespace std;

const int maxN = 5e4;

struct Edge{
	int a, b, c;
	Edge(){}
	Edge(int a, int b, int c): a(a), b(b), c(c){}
};
vector<Edge> edges;

string dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/turtlechain/tc5/";
int st = 41, en = 50;


int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	for(int T = st; T <= en; T++){
		cout << "Doing testcase " << T << endl;
		ofstream file;
		file.open(dir + to_string(T) + ".in");
		int N = rnd.wnext(maxN, 4);
		int K = rnd.next(1, 5);
		int M = 0;
		int Q = rnd.wnext(maxN, 5);
		edges.clear();
		for(int i = 0; i < N; i++){
			for(int j = 0; j < K; j++){
				for(int k = 0; k < K; k++){
					if(rnd.wnext(10, 2) > 5){
						edges.emplace_back(i, j, k);	
						M++;
					}
				}
			}
		}
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		shuffle(edges.begin(), edges.end(), default_random_engine(seed));
		file << N << " " << K << " " << min(M, maxN) << " " << Q << endl;
		int cnt = 0;
		for(auto e : edges){
			cnt++;
			file << e.a << " " << e.b << " " << e.c << endl;
			if(cnt == maxN) break;
		}
		for(int q = 0; q < Q; q++){
			if(rnd.wnext(100, 2) > 50){
				int k = rnd.next(0, N - 1), a = rnd.next(0, N - 1), b = rnd.next(0, K - 1), c = rnd.next(0, N - 1), d = rnd.next(0, K - 1);	
				file << "B " << k << " " << a << " " << b << " " << c << " " << d << endl;
			} else {
				int a = rnd.next(0, N - 1), b = rnd.next(0, K - 1), c = rnd.next(0, K - 1);	
				file << "C " << a << " " << b << " " << c << endl;
			}
		}
		file.close();
	}
	
}
