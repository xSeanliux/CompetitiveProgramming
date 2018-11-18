#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N, M, C = 0;

int main(){
    while(cin >> N){
        if(!N) return 0;
        int arr[N];
        for(int i = 0 ; i < N; i++)
            cin >> arr[i];
        sort(arr, arr + N);
        cin >> M;
        int target;
        printf("Case %d:\n", ++C);
        for(int i = 0; i < M; i++){
            cin >> target;
            int head = 0, tail = N-1;
            while(head < tail){
                if(arr[head] + arr[tail] < target && abs(target - arr[head] - arr[tail]) > abs(target - arr[head+1] - arr[tail]) && tail - head > 1){
                    head++;
                } else if(arr[head] + arr[tail] > target && abs(target - arr[head] - arr[tail]) > abs(target - arr[head] - arr[tail-1]) && tail - head > 1){
                    tail--;
                } else {
                    break;
                }
            }
            printf("Closest sum to %d is %d.\n", target, arr[head] + arr[tail]);
        }
    }
}
