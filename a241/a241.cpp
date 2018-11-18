#include <iostream>
#include <math.h>

using namespace std;
bool primes[10006];
int sum = 0;
int f(int N){
    sum = 0;
    double prod = 0;
    for(long long int i = 0; i <= 27; i++){
        for(long long int j = 0; j <= 12; j++){
            prod = pow(2, i) * pow(5, j);
            if(prod <= N){
                //printf("1/%d is a non-repeating decimal.\n", prod);
                sum++;
            }

        }
    }

    //cout << sum-1 << endl; //take away one because 1/1 does not count.
    return sum-1;

}


int main(){
    int cases, N;
    for(int i = 0 ; i < 10006; i++){
            primes[i] = true;
        }
        primes[0] = false;
        primes[1] = false;
        for(int i = 2; i*i < 10006; i++){
            if(primes[i]){
                for(int j = i*i ; j < 10006; j += i){
                    primes[j] = false;
                }
            }
        }
    while(cin >> cases){ //Can't be divisible by any other prime than 2 or 5 -> the numbers are all of format 2^n*5^m





        for(int i = 0 ; i < cases; i++){
                cin >> N;
                cout << f(N) << endl;



        }
    }
}
//101 is the one I have to crack.



