#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
/*
long long int arr[1000000];
int head = 0;
bool isSquare(int N){
    //cout << N << " " << sqrt(N) << endl;
    return (floor(sqrt(N))*floor(sqrt(N)) == N);
}

int digSum(long long int N){
    int res = 0;
    while(N > 0){
        int r = N % 10;
        res += r;
        N -= r;
        N /= 10;
    }

    return res;
}


int main(){
    head = 0;
    long long int k;
    //cout << isSquare(81) << endl;
    cout << isSquare(digSum(998001)) << endl;
    for(k = 1; k < 100000; k++){
        if(isSquare(digSum(k * k))){
            //cout << k << " " << k * k<< " " << digSum(k * k) << endl;
            arr[head] = k;
            //if(head > 0) cout << arr[head] - arr[head - 1] << endl;
            head++;
        }
    }
    sort(arr, arr + head);
    for(int i = 6 ; i < head; i++){
        for(int z = i - 5; z <= i + 1; z++){
            if(arr[z] - arr[z - 1] != 1){
                break;
            } else if(z == i){
                for(int r = i - 6; r <= i; r++){
                    cout << arr[r] << " " << arr[r]*arr[r] << endl;
                }
            }
        }
    }
}
*/
int main(){
    for(long long int i = 9999; i <= 10005; i++){
        printf("%d %lld\n", i, i*i);
    }
}

