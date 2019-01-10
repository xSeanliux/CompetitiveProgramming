#include <iostream>
#define LL long long
using namespace std;

LL int B, P, M;

int go(unsigned LL int B, unsigned LL int P, unsigned LL int M){
    unsigned LL int mask = 1, current = B, ans = 1;
    while(mask <= P){
        if((mask & P)){
            //printf("%lld & %lld = %lld\n", mask, P , (mask & P));
            ans = (current * ans) % M;
            //cout << "Times 2^" << mask << endl;
        }
        mask <<= 1;
        current = (current * current) % M;
        //cout << "mask = " << mask << endl;
    }
    return ans;
}

int main(){
    while(cin >> B >> P >> M){
        cout << go(B % M, P, M) << endl;
    }
}
