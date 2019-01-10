#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    bool arr[N+1];
    for(int i = 1; i <= N; i++){
        scanf("%d", &arr[i]);
    }
    long long int ans = 0;
    for(int i = N; i >= 1; i--){
        if(!arr[i]){
            ans++;
            for(int j = 1; j*j <= i; j++){
                if(!(i % j)){
                    arr[j] = !arr[j];
                    if(j != i/j)
                        arr[i/j] = !arr[i/j];
                }
            }
        }
    }
    printf("%lld\n", ans);
}
