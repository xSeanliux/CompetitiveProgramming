#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#define int unsigned long long int
using namespace std;


set<int> st;
vector<int> powers;
const double eps = 1e-8;
const int maxN = 1e18;

int exp(int b, int e){
    if(e == 1) return b;
    int res = exp(b, e/2);
    res = res * res;
    if(e % 2) res = res * b;
    return res;
}



void getPows(){
    st = set<int>();
    powers.clear();
    for(int p = 5; p <= 60; p += 2){ //2! incl-excl
        if(p % 3 == 0) continue;
        for(int a = 1; a <= (int)pow(maxN, 1.0/p); a++){
            if( (int)pow((int)(pow(a, 0.5) + eps), 2) == a || (int)pow((int)(pow(a, 1.0/3) + eps), 3) == a || st.count(exp(a, p))) continue;
            st.insert(exp(a, p));
        }
    }
    for(int i : st){
        powers.push_back(i);
    }
}

int getAns(int x){
    int res;
    if(!x) return 0;
    for(int i = sqrt(x) - 1; i <= sqrt(x) + 1; i++){
        if(i * i <= x && (i + 1) * (i + 1) > x){
            res = i;
            break;
        }
    }
    for(int i = pow(x, 1.0/3) - 1; i <= pow(x, 1.0/3) + 1; i++){
        if(pow(i, 3) <= x && pow(i + 1, 3) > x){
            res += i;
            break;
        }
    }
    for(int i = pow(x, 1.0/6) - 1; i <= pow(x, 1.0/6) + 1; i++){
        if(pow(i, 6) <= x && pow(i + 1, 6) > x){
            res -= i;
            break;
        }
    }
    return res + (upper_bound(powers.begin(), powers.end(), x) - powers.begin());
}

int Q, L, R;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(0);
    getPows();
    //cout << "DONE" << endl;
    cin >> Q;
    while(Q--){
        cin >> L >> R;
        cout << getAns(R) - getAns(L - 1) << endl;
    }
}
/*
3
1 1000000000000000000
2 999999999999999999


*/
