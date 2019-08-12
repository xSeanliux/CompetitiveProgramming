#include <iostream>
#include <vector>
using namespace std;

long long int N, ans = 0;
vector<long long int> Vec;
const int MOD = 10000019;

void Merge(vector<long long int> &vec){
    //for(int i : vec){
    //    cout << " " << i;
    //}
    //cout << endl;
    if(vec.size() == 1) return;
    vector<long long int> lft, rt;
    for(int i = 0; i < vec.size(); i++){
        ((i < vec.size() / 2) ? lft : rt).push_back(vec[i]);
    }
    Merge(lft);
    Merge(rt);
    //create two sorted arrays
    vector<long long int> nInt;
    //merge
    long long int l = 0, r = 0, pre = 0, cnt = 0;
    long long int _ans = 0;
    while(nInt.size() < vec.size()){
        if(l == rt.size() && r == rt.size()) break;
        if(r == rt.size()){
            _ans = (_ans + lft[l] * cnt % MOD + pre % MOD + MOD) % MOD;
            nInt.push_back(lft[l++]);
            if(l == rt.size() && r == rt.size()) break;
            continue;
        }
        if(l == lft.size()){
            pre += rt[r];
            cnt++;
            nInt.push_back(rt[r++]);
            if(l == rt.size() && r == rt.size()) break;
            continue;
        }
        if(lft[l] <= rt[r]) {
            _ans = (_ans + lft[l] * cnt % MOD + pre % MOD + MOD) % MOD;
            nInt.push_back(lft[l++]);
        } else{
            pre += rt[r];
            cnt++;
            nInt.push_back(rt[r++]);
        }
    }
    //cout << "ANS: " << _ans << endl;
    ans += _ans;
    ans %= MOD;
    vec = nInt;
    return;
}

int main(){
    cin >> N;
    Vec.clear(); Vec.resize(N);
    for(int i = 0; i < N; i++) cin >> Vec[i];
    ans = 0;
    Merge(Vec);
    cout << ans % MOD << endl;
}
