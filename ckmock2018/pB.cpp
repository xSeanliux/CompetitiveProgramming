#include <iostream>
#include <algorithm>
using namespace std;

long long int c, N, head;

struct Doll{
    long long int w, h;
} dolls[20000 + 5];

long long int Hs[20000 + 5], dp[20000 + 5];

Doll finalDolls[20000  +5];

void LIS(){
    fill(dp, dp + N, 2147);
    for(int i = 0 ; i < head; i++){
        *lower_bound(dp, dp+N, Hs[i]) = Hs[i];
    }
    cout << lower_bound(dp, dp + N, 2147) - dp << endl;
}

bool wComp(const Doll a, const Doll b){
    if(a.w == b.w){
        return a.h > b.h;
    }
    return a.w < b.w;
}


int main(){
    cin >> c;
    for(int ka = 0 ; ka < c; ka++){
        cin >> N;
        for(int i = 0 ; i < N; i++){
            cin >> dolls[i].w >> dolls[i].h;
        }
        sort(dolls, dolls + N, wComp); //then run LIS on the H
        head = 0;
        long long int maxW = 0;

        for(int i = 0 ; i < N; i++){
                /*
            if(dolls[i].w >= maxW){
                maxW = dolls[i].w + 1;
                Hs[head] = dolls[i].h;
                //cout << "found: " << dolls[i].w << ", " << dolls[i].h << endl;
                head++;
            }
            */
            Hs[i] = dolls[i].h;
            head++;
        }

        //run LIS on finalDolls' H
        LIS();
    }
}
