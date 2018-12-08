#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000 + 10];
int N;
int main(){
    while(cin >> N){
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
        }
        sort(arr + 1, arr+N + 1);
        if(!(N & 1)){
            cout << arr[N/2] << " " << (upper_bound(arr + 1, arr + N + 1, arr[N/2 + 1]) - arr) - (lower_bound(arr + 1, arr + N + 1, arr[N/2]) - arr) << " " << arr[N/2 + 1] - arr[N/2] + 1 << endl;
        } else {
            cout << arr[(N+1)/2] << " " << (upper_bound(arr + 1, arr + N + 1, arr[(N+1)/2]) - arr) - (lower_bound(arr + 1, arr + N + 1, arr[(N+1)/2]) - arr) << " 1" << endl;
        }
    }
}
