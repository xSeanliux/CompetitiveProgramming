#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[105];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    int ans = 0;
    for(int i = 1; i < N; i+=2){
        ans += arr[i] - arr[i-1];
    }
    cout << ans << endl;
}
