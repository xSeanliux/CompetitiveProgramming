#include <iostream>
using namespace std;

int N, K;

int main(){
    while(scanf("%d%d", &N, &K)){
        if(N == -1 && K == -1) return 0;
        int coeff[N + 1]; //coeff[i] = a_{N - i}
        for(int i = N; i >= 0; i--){
            scanf("%d", &coeff[i]);
        }
        if(!K){
            printf("0\n");
            continue;
        }
        for(int i = 0; i < N-K+1; i++){
            coeff[i+K] -= coeff[i];
            coeff[i] = 0;
            /*
            for(int i = 0; i <= N; i++){
                cout << coeff[i] << " ";
            }
            cout << endl;
            */
        }
        int ind;
        for(ind = 0; ind <= N; ind++)
            if(coeff[ind] != 0) break;
        if(ind >= N){
            printf("%d\n", coeff[N]);
        } else {
            printf("%d", coeff[N]);
            for(int i = N-1; i >= ind; i--){
                printf(" %d", coeff[i]);
            }
            printf("\n");
        }
    }
}
