#include <iostream>
#pragma GCC optimize ("O3")
#include <algorithm>
using namespace std;

int N;

int main(){
    cin >> N;
    int arr[N + 1];
    for(int i = 0 ; i < N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    for(int i = 1; i < N; i++){
        if(arr[i] - arr[i-1] != 1){
            printf("%d %d no\n", arr[0], arr[N-1]);
            return 0;
        }
    }
    printf("%d %d yes\n", arr[0], arr[N-1]);
}
