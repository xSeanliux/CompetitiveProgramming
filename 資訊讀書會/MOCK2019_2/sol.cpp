#include <iostream>
#include <fstream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e4;

int pre[maxN + 10], N, Q, x, y;
string s = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/資訊讀書會/MOCK2019_2/test_3";


signed main(){
    ericxiao;
    ofstream outfile;
    ifstream infile;
    for(int t = 9; t <= 13; t++){
        infile.open(s + "/" + to_string(t) + ".in");
        outfile.open(s + "/" + to_string(t) + ".out");
        cout << "Running test" << endl;
        infile >> N;
        fill(pre, pre + (int)(1e4) + 1, 0);
        for(int i = 0; i < N; i++){
            infile >> x >> y;
            pre[x]++;
        }
        for(int i = 1; i <= maxN; i++) pre[i] += pre[i - 1];
        infile >> Q;
        int A, B, C;
        while(Q--){
            infile >> x;
            A = pre[x - 1];
            C = pre[maxN] - pre[x];
            B = pre[x] - pre[x - 1];
            outfile << A * (B + C) + B * (B - 1) / 2 + B * C << '\n';
        }
        infile.close();
        outfile.close();
    }
}
