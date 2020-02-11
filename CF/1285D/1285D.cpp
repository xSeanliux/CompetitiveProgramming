#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10, maxLog = 32;

int currentXor = 0, N, currentMax, newMax;
vector<int> vals;

int solve(vector<int> arr, int dig){
    if(dig == 0){
        bool hasZ = false, hasO = false;
        for(int x : arr){
            if(x == 1) hasO = true;
            if(x == 0) hasZ = true;
        }
        return hasO & hasZ;
    }
    vector<int> has, nhas;
    for(int x : arr){
        if((x & (1LL << dig)) > 0){
            has.push_back(x ^ (1LL << dig));
        } else nhas.push_back(x);
    }
    //cout << "For dig = " << dig << ": ";
    //cout << "has:"; for(int x : has) cout << " " << x;
    //cout << endl << " nhas:"; for(int x : nhas) cout << " " << x;
    //cout << endl;
    if(!has.size()) return solve(nhas, dig - 1);
    else if(!nhas.size()) return solve(has, dig - 1);
    return (1LL << dig) + min(solve(nhas, dig - 1), solve(has, dig - 1));
}

signed main(){
    cin >> N;
    vals.resize(N);
    for(int i = 0; i < N; i++) cin >> vals[i];
    cout << solve(vals, maxLog) << endl;
}
