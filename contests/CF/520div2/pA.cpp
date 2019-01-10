#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    int arr[N+2];
    arr[0] = 0;
    arr[N+1] = 1001;
    for(int i = 1 ; i <= N; i++){
        cin >> arr[i];
    }
    int ans = 0, maxAns = 0;
    for(int i = 1; i <= N; i++){
        ans = 0;
        while(arr[i] - arr[i-1] == 1 && arr[i+1] - arr[i] == 1){
            i++;
            ans++;
        }
        maxAns = max(ans, maxAns);
    }
    cout << maxAns << endl;
}
