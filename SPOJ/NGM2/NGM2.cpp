#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int N, K, vals[20];

bool hasBit(int x, int b){
    return (x & (1LL << b)) > 0;
}

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}

signed main(){
    cin >> N >> K;
    int ans = N;
    for(int i = 0; i < K; i++){
        cin >> vals[i];
    }
    int g;
    vector<int> ind;
    for(int i = 1; i < (1LL << K); i++){
        //cout << "i = " << i << endl;
        ind.clear();
        for(int j = 0; j < K; j++){
            if(hasBit(i, j)){
                //cout << "j = " << j << endl;
                ind.push_back(j);
            }
        }
        g = vals[ind[0]];
        for(int v : ind){
            g = g * vals[v] / gcd(vals[v], g);
            //cout << "vals[" << v << "]= " << vals[v] << endl;
            //cout << "G = " << g << endl;
        }
        if(ind.size() % 2){
            ans -= N / g;
        } else {
            ans += N / g;
        }
    }
    cout << ans << endl;
}
