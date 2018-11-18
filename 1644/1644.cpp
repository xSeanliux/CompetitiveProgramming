#include <iostream>
#define MN 1299709
using namespace std;

bool isPrime[1299709 + 1000];
long long int k, u, l;
int findPrimes(){
    for(int i = 0 ; i <= MN; i++){
        isPrime[i] = (i%2);
    }
    isPrime[1] = 0;
    isPrime[2] = 1;
    for(long long int i = 3; i <= MN; i+=2){
        if(isPrime[i]){
            //cout << i << endl;
            for(long long int j = i*i ; j <= MN; j += i){
                //cout << j << endl;
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    findPrimes();
    while(cin >> k){
        if(!k) return 0;
        //cout << isPrime[k] << endl;
        if(isPrime[k]){
            printf("0\n");
        } else {
            for(int i = k ; i <= MN; i++){
                if(isPrime[i]){
                    u = i;
                    break;
                }
            }
            for(int i = k ; i > 1; i--){
                if(isPrime[i]){
                    l = i;
                    break;
                }
            }
            printf("%d\n", u - l);
            //printf("K: %d U: %d, L: %d, ans: %d\n", k, u, l, u - l);
        }

    }
}
