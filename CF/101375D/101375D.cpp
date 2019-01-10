#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    unsigned long long int ans = 0, sum = 0;
    unsigned long long int arr[N];
    for(int i = 0; i < N; i++){
        scanf("%llu", &arr[i]);
        sum += arr[i];
    }
    for(int i = 0; i < N; i++){
        ans += (sum - arr[i]) * arr[i];
    }
    printf("%llu\n", ans/2);
}
