#include <iostream>
#include <string.h>
#include <math.h>
#define N 1000003
#define E 2.71828182845904553488
using namespace std;

int arr[N], k, currentMax = 1;

int main(){
    for(int i = 0; i < N; i++)
        arr[i] = -1;
    arr[0] = 1;
    //for(int i = 1; i <= N; i++){
    //        arr[i] = (arr[ (int)(i - sqrt(i)) ] + arr[ (int)(log(i)) ] + arr[ (int)(i * sin(i) * sin(i)) ]) % 1000000;
    //        printf("%d, %d, %d\n",  (int)(i - sqrt(i)), (int)(log(i)), (int)(i * sin(i) * sin(i)));
    //}
    while(scanf("%d", &k)){
        if(k == -1) return 0;
        if(arr[k] == -1){
            for(int i = currentMax; i <= k; i++){
                arr[i] = (arr[ (int)(i - sqrt(i)) ] + arr[ (int)(log(i)) ] + arr[ (int)(i * sin(i) * sin(i)) ]) % 1000000;
                //cout << "arr[" << i << "] = " << arr[i] << endl;
            }
            currentMax = k + 1;
        }
        printf("%d\n", arr[k]);
    }
}
