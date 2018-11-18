#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    bool arr[N];
    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 1; i < N-1; i++){
        if(arr[i-1] && arr[i+1] && !arr[i]){
            ans++;
            arr[i+1] = 0;
        }
    }
    cout << ans << endl;
}
