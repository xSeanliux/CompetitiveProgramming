#include <iostream>
#include <algorithm>
using namespace std;

long long int N, ans = 2147483647;

int main(){
    cin >> N;
    long long int arr[2 * N + 1];
    for(int i = 0; i < 2*N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + 2*N);
    long long int ans = (arr[2*N - 1] - arr[N]) * (arr[N-1] - arr[0]);
    long long int minDist = 2147483647;
    for(int i = 1; i <= N; i++){
        minDist = min(minDist, arr[i + N - 1] - arr[i]);
    }
    printf("%lld\n", min(ans, minDist * (arr[2*N - 1] - arr[0])));
}
