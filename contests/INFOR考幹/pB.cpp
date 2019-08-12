#include <iostream>
#include <vector>
#define lli long long int
#define ulli unsigned long long int
using namespace std;

const lli MOD = 880301;
lli q, facts[MOD + 1], invfacts[MOD + 1];
ulli a, b;
vector<lli> acoeffs, bcoeffs;

void extgcd(lli a, lli b, lli& x, lli &y, lli& d){
    if(!b){
        d = a;
        x = 1;
        y = 0;
        return;
    } else {
        extgcd(b, a % b, y, x, d);
        y -= a/b * x;
    }
}

lli choose(lli a, lli b){
    //cout << "Running " << a << " choose " << b << endl;
    if(a < b) {
        //cout << " is smaller!" << endl;
        return 0;
    }
    //printf("%lld! = %lld, %lld! = %lld, %lld! = %lld\n", a, facts[a], b, invfacts[b], a - b, invfacts[a- b]);
    return facts[a] * invfacts[b] % MOD * invfacts[a - b] % MOD;
}

lli inv(lli x){
    lli inverse, u, d;
    extgcd(x, MOD, inverse, u, d);
    while(inverse < 0) inverse += MOD;
    return inverse % MOD;
}

int main(){
    facts[0] = 1;
    invfacts[0] = 1;
    for(int i = 1; i <= MOD; i++) {
            facts[i] = (facts[i-1] * i) % MOD;
            invfacts[i] = inv(facts[i]);
    }
    scanf("%lld", &q);
    while(q--){
        scanf("%llu%llu", &a, &b);
        acoeffs.clear();
        bcoeffs.clear();
        while(a){
            acoeffs.push_back(a % MOD);
            a /= MOD;
            if(!a) break;
        }
        while(b){
            bcoeffs.push_back(b % MOD);
            b /= MOD;
            if(!b) break;
        }
        while(bcoeffs.size() < acoeffs.size()) bcoeffs.push_back(0);
        lli res = 1;
        for(int i = 0; i < acoeffs.size(); i++){
            res = res * choose(acoeffs[i], bcoeffs[i]) % MOD;
            //cout << choose(acoeffs[i], bcoeffs[i]) << endl;
        }
        printf("%lld\n", res);
    }
}
