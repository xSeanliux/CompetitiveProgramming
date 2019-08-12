#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define int long long int
using namespace std;

vector<int> vals, ind;
int N;

signed main(){
    cin >> N;
    vals.resize(N); ind.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vals[i];
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [](int a, int b){
        return vals[a] > vals[b];
    });
    int maxAns = 1e12, minI = ind[0], maxI = ind[0];
    for(int i = 1; i < ind.size(); i++){
        maxAns = min(maxAns, vals[ind[i]] / max(abs(ind[i] - minI), abs(ind[i] - maxI)));
        minI = min(minI, ind[i]);
        maxI = max(maxI, ind[i]);
    }
    cout << maxAns << endl;
}
