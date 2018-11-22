#include <iostream>
using namespace std;

int arr[10 + 5];

int n, N;

int f(int N){
    if(N == 0) return 0;
    int t = N;
    while(N > 0){
        arr[N%10]++;
        N /= 10;
    }
}

int main(){
    cin >> n;
    for(int j = 0; j < n; j++){
        cin >> N;
        for(int i = 0 ; i <= 10; i++){
            arr[i] = 0;
        }
        for(int i = 1; i <= N; i++){
            f(i);
        }
        for(int i = 0; i < 9 ; i++){
            cout << arr[i] << " ";
        }
        cout << arr[9] << endl;

    }
}

