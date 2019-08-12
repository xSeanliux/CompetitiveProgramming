#include <iostream>
#include <math.h>
#include <algorithm>
#define int unsigned long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5;

int N, vals[maxN + 10], hashpre[maxN + 10], hashval[maxN + 10], hashsum[maxN + 10];

int calc(int pos){
    int r = pos, len = 1, res = 0;
    while(r < N && vals[r + 1] != 1){
        r++;
        len = max(len, vals[r]);
        if(r - len >= 0){
            if((hashpre[r] ^ hashpre[r - len]) == hashsum[len]){
                res++;
            }
        }
    }
    return res;
}

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 1; i <= N; i++){
        hashval[i] = 0;
        for(int j = 0; j < 4; j++){
            hashval[i] <<= 32;
            hashval[i] |= rand();
        }
    }

    for(int i = 1; i <= N; i++){
        cin >> vals[i];
    }

    hashsum[0] = 0;
    hashpre[0] = 0;
    for(int i = 1; i <= N; i++){
        hashsum[i] = hashval[i] ^ hashsum[i - 1];
        hashpre[i] = hashpre[i - 1] ^ hashval[ vals[i] ];
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(vals[i] == 1){
            ans += calc(i) + 1;
        }
    }
    reverse(vals + 1, vals + N + 1);
    for(int i = 1; i <= N; i++){
        hashpre[i] = hashpre[i - 1] ^ hashval[ vals[i] ];
    }
    for(int i = 1; i <= N; i++){
        if(vals[i] == 1){
            ans += calc(i);
        }
    }
    cout<< ans << endl;

}
