#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define S second
#define F first
#define int unsigned long long int
using namespace std;

map<int, vector<int> > poss;

int N, x;

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        poss[x].push_back(i);
    }
    int nume = 0, c = 0;
    for(auto p : poss){
        c = 0;
        //cout << "For " << p.F << endl;
        c += p.S[0] * p.S[0];
        //cout << "from 0 to " << p.S[0] << endl;
        for(int i = 1; i < p.S.size(); i++){
            c += (p.S[i] - p.S[i - 1] - 1) * (p.S[i] - p.S[i - 1] - 1);
            //cout << "from " << p.S[i - 1] << " to " << p.S[i] << endl;
        }
        c += (N - p.S[p.S.size() - 1] - 1) * (N - p.S[p.S.size() - 1] - 1);
        //cout << "from " << p.S[p.S.size() - 1] << " to " << N << endl;
        nume += N * N - c;
    }
    double n = nume, d = N * N;
    cout << setprecision(9) << n/d << endl;
}
