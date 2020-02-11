#include <iostream>
using namespace std;

const int maxN = 226;

int T, N, arr[maxN], ans, sum;

int main(){
    cin >> T;
    while(T--){
        ans = sum = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            if(!arr[i]){
                ans++;
                arr[i]++;
            }
            sum += arr[i];
        }
        if(!sum) ans++;
        cout << ans << endl;
    }
}
