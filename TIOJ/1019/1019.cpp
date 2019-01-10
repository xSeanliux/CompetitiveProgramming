#include <iostream>
#include <math.h>
using namespace std;
int T, N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        long long int arr[N], dp[N];
        for(int i = 0 ; i < N; i++){
            cin >> arr[i];
            dp[i] = 0;
        }
        if(N == 2) {
            cout << abs(arr[1] - arr[0]) << endl;
            continue;
        }
        dp[0] = 0;
        dp[1] = arr[1] - arr[0];
        for(int i = 2; i < N; i++){
            dp[i] = dp[i-1] + abs(arr[i] - arr[i-1]);
            for(int j = 0; j < i; j++){
                dp[i] = min(dp[i], dp[j] + abs(arr[j] - arr[i]));
            }
        }
        cout << dp[N-1] << endl;
    }
}
