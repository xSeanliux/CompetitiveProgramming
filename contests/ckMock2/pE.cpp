#include <iostream>
using namespace std;

int N, Q, l, r, a, b;

int main(){
    cin >> N >> Q;
    long long int arr[N + 1];
    for(int i = 1; i <= N; i++){
        scanf("%lld", &arr[i]);
    }
    while(Q--){
        scanf("%d %d %d %d", &l, &r, &a, &b);
        long long int ans = 0;
        if(a > b) swap(a, b);
        for(int i = l; i <= r; i++){
            if(arr[i] <= b && arr[i] >= a){
                ans += arr[i];            }
        }
        printf("%lld\n", ans);
    }
}
