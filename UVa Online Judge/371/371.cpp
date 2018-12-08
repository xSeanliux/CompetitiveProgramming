#include <iostream>
using namespace std;

int len(long long int N){
    int len = 0;
    do{
        if(!(N%2)){
            N = N >> 1;
        } else {
            N = 3*N + 1;
        }
        len++;
    }while(N!=1);
        return len;
}
long long int L, H;
int main(){
    while(cin >> L >> H){
        int m = L, mL = 0;
        if(L > H) swap(L, H);
        if(!L && !H) return 0;
        for(long long int i = L; i <= H; i++){
            int z = len(i);
            if(z > mL){
                mL = z;
                m = i;
            }
        }
        printf("Between %d and %d, %d generates the longest sequence of %d values.\n", L, H, m, mL);
    }
}
