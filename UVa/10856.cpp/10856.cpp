#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

long long int N[10000001 + 5];
long long int M[10000001 + 5];
bool isPrime[3000000];
long long int primes[3000000];
int k = 1;
void getPrimes(){
    for(int i = 0; i < 2703665; i++){
        isPrime[i] = true;
    }
    for(int i = 2; i*i < 2703665; i+=1){
        if(isPrime[i]){
            for(long long int j = i*i; j < 2703665; j += i){
                //cout << j << endl;
                if(j > 0){

                    isPrime[j] = false;

                } else {
                    break;
                }
            }
        }
    }
    for(int i = 3; i < 2703665; i+=1){
        if(isPrime[i]){
            //cout << i << "  " << k << endl;
            primes[k] = i;
            k++;
        }
    }

}

int main(){
    getPrimes();
    //cout << "p " << endl;
    primes[0] = 2;
    N[1] = 0; //1! has 0 prime factors
    N[2] = 1; //2! has 1 prime factor
    int ans = 0;
    for(int j = 0; j < 10000001; j++){
            N[j] = 0;
    }
    for(int i = 0; i < k; i++){ //nth prime
        int p = primes[i];
        for(int j = p; j < 2703664; j += p){
            int b = j;
            while(b % p == 0){
                N[j]++;
                b /= p;

            }
        }
    }
    M[0] = 0;
    M[1] = 0;
    for(int i = 2; i < 10000001; i++){
        M[i] = M[i-1] + N[i];
        //cout << i << "  " << N[i] << endl;
    }
    //cout << "Done" << endl;
    int query;
    int c = 1;
    while(cin >> query){
        if(query < 0){
            return 0;
        } else {
            cout << "Case " << c << ": ";
            bool found = false;
            for(int i = 0; i < 10000001; i++){
                if(query == M[i]){
                    cout << i << "!" << endl;;
                    found = true;
                    break;
                } else if(query < M[i] && !found){
                    cout << "Not possible." << endl;
                    break;
                }
            }
        }
        c++;
    }
}
