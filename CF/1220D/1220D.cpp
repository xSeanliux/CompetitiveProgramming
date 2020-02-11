#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int maxSz = 0, maxPow, N, x;
vector<int> szs[61];

inline void ins(int x){
    int p = 0;
    int o = x;
    while(!(x % 2)){
        x /= 2;
        p++;
    }
    szs[p].push_back(o);
    if(maxSz < szs[p].size()){
        maxSz = szs[p].size();
        maxPow = p;
    }
}

signed main(){
    ericxiao;
    cin >> N;
    while(N--){
        cin >> x;
        ins(x);
    }
    int K = 0;
    for(int i = 0; i <= 60; i++){
        if(i != maxPow) K += szs[i].size();
    }
    cout << K << endl;
    for(int i = 0; i <= 60; i++){
        if(i != maxPow){
            for(int v : szs[i]) cout << v << " ";
        }
    }
}
