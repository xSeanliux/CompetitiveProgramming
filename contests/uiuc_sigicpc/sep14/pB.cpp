#include <iostream>
using namespace std;

const int maxN = 3e5 + 326;
int N, arr[maxN];

int main(){
    cin >> N;
    int maxAt = -1;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(arr[i] == N) maxAt = i;
    }
    bool f = true;
    for(int i = maxAt - 1; i >= 0; i--) f &= (arr[i] < arr[i + 1]);
    for(int i = maxAt; i < N - 1; i++) f &= (arr[i] > arr[i + 1]);
    cout << (f ? "Yes" : "No") << endl;
}
