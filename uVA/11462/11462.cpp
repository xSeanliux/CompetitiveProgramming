#include <iostream>
using namespace std;

long long int N;
long long int freqs[103];

int main(){
    while(scanf("%lld", &N)){

        if(!N) return 0;
    for(int i = 0; i < 101; i++){
            freqs[i] = 0;
        }
        int t;
        for(int i = 0; i < N; i++){
            scanf("%d", &t);
            freqs[t]++;
        }
        bool hasPrinted = false;
        for(int i = 0; i < 101; i++){
            if(freqs[i] >= 1){
                for(int j = 0; j < freqs[i]; j++){
                    if(hasPrinted){
                        cout << " ";
                    } else {
                        hasPrinted = true;
                    }
                    cout << i ;

                }
            }
        }
        cout << endl;
    }
}
