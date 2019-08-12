#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M, arr[10005], ans1, ans2, minDiff;
bool flag = false ;

int main(){
    while(cin >> N){
        for(int i = 0; i < N; i++) cin >> arr[i];
        cin >> M;
        sort(arr, arr + N);
        minDiff = 2147483647;
        for(int i = 0; i < N && arr[i] <= M/2; i++){
            if(*lower_bound(arr, arr + N, M - arr[i]) == M - arr[i]){
                if(minDiff > abs(M - 2 * arr[i])){
                    ans1 = arr[i];
                    ans2 = M - arr[i];
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", ans1, ans2);
    }
}
