#include <iostream>
#include <algorithm>
using namespace std;

int N;

int main(){
    while(cin >> N){
        if(!N) return 0;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        sort(arr, arr + N);
        long long int ans = 0;
        ans += (N-1)*arr[0];
        for(int i = 1; i < N; i++){
            ans += (N - i)*arr[i];
        }
        cout << ans << endl;
    }
}
