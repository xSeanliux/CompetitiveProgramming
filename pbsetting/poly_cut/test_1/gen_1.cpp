#include "testlib.h"
#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e6, INF = 1e8;
string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/poly_cut/test_1";

/*
Test 1:
3 cases
N <= 3
K no restrictions
*/

int caseCount = 3, N = 3, m;
pii points[maxN], ch[maxN];

pii operator-(pii a, pii b){
    return {a.F - b.F, a.S - b.S};
}

int operator*(pii a, pii b){
    return a.F * b.S - a.S * b.F;
}
std::random_device rd; // 種子產生器
    std::mt19937 gen = std::mt19937(rd()); //使用mt19937引擎
    std::uniform_real_distribution<> dis(-1, 1); //使用平均分佈


signed main(signed argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ofstream myfile;
    for(int i = 0; i < maxN; i++){
        points[i] = {rnd.next(-INF, INF), rnd.next(-INF, INF)};
        cout << points[i].F << " " << points[i].S << '\n';
    }
    cout << endl;
    sort(points, points + maxN);
    for(int i = 0; i < maxN; i++){
        while(m > 1 && (ch[m - 1] - ch[m - 2]) * (points[i] - ch[m - 1]) <= 0) m--;
        ch[m++] = points[i];
    }
    int bottomsz = m;
    for(int i = maxN - 2; i >= 0; i--){
        while(m > bottomsz && (ch[m - 1] - ch[m - 2]) * (points[i] - ch[m - 1]) <= 0) m--;
        ch[m++] = points[i];
    }
    m--;
    for(int i = 0; i < m; i++){
        cout << ch[i].F << " " << ch[i].S << '\n';
    }

    cout << "m = " << m << endl;

    for(int k = 1; k <= caseCount; k++){
        myfile.open (s + "/" + to_string(k) + ".in");
        int N = 3;
        for(int i = 0; i < N; i++){
            points[i] = {rnd.next(-INF, INF), rnd.next(-INF, INF)};
        }

        myfile.close();
    }

}
