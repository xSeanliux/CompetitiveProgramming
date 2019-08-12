#include <iostream>
#include <math.h>
using namespace std;

int Q, N;
long long int answs[26];

long long int gcd(long long int a, long long int b){
    return (!b) ? a : gcd(b, a % b);
}

long long int inv(long long int x){
    return (long long int)pow(2, ceil(log2(N + 1))) - 1 - x;
}

int main(){
    cin >> Q;
    //cout << (1 << 25) - 1 << endl;
    for(int i = 0; i <= 25; i++) answs[i] = -1;
    answs[19] = 1;
    answs[20] = 349525;
    answs[21] = 299593;
    answs[22] = 1398101;
    answs[23] = 178481;
    answs[24] = 5592405;
    answs[25] = 1082401;
    while(Q--){
        cin >> N;
        bool flag = false;
        for(int i = 2; i <= 1 << 25; i <<= 1){
            if(N == i-1){
                //cout << N << " = 2^" << (int)(log2(i)) << " - 1" << endl;
                if(answs[(int)log2(i)] < 0) {
                    long long int ms = 0;
                    for(int j = 1; j < N/2 + 1; j++){
                        ms = max(ms, gcd(j, N - j));
                    }
                    answs[(int)log2(i)] = ms;
                }
                cout << answs[(int)log2(i)] << endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << (long long int)pow(2, ceil(log2(N + 1))) - 1 << endl;
        }
    }
}
