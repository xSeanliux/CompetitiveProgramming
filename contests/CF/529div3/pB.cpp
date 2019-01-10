#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[100006];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cout << min(arr[N-1] - arr[1], arr[N-2] - arr[0]);
}
