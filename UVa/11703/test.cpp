
#include <iostream>
#include <string.h>
#include <math.h>
#define N 1000006
#define E 2.71828182845904553488
using namespace std;

int arr[N], k, currentMax = 1;

bool getE(){
    unsigned long long int fact = 1;
    double e = 1;
    for(int i = 1; fact > 0; i++){
        fact *= i;
        e += 1.0/fact;
        //printf("%.20f\n", e);
    }
    //printf("%.10llf\n", e);
}


int getLog(int K){
    int currentLogNum = 0;
    double pow = 1;
    while(pow <= K){
        //cout << pow << " <= " << K << endl;
        pow *= E;
        currentLogNum++;
    }
    //cout << "Ans: " << pow - 1 << endl;
    return currentLogNum-1;
}

int getSqrt(int K){
    int ans = 1;
    while(ans*ans < K){
        ans++;
    }
    return ans;
}



int main(){
    getE();
    for(int i = 0; i < N; i++)
        arr[i] = -1;
    arr[0] = 1;
    while(scanf("%d", &k)){
        if(k == -1) return 0;
        double s;
        if(arr[k] == -1){
            for(int i = currentMax; i <= k; i++){
                arr[i] = (arr[ (int)(i - sqrt(i)) ] + arr[ (int)(log(i)) ] + arr[ (int)(i * sin(i) * sin(i)) ]) % 1000000;
                //printf("%d, %d, %d\n", (i - getSqrt(i)), getLog(i), (int)(i * sin(i) * sin(i)));

                //cout << "arr[" << i << "] = " << arr[i] << endl;
            }
            currentMax = k + 1;
        }
        printf("%d\n", arr[k]);
    }
}
