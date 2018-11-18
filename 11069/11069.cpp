#include <iostream>
using namespace std;

unsigned long long int arr[100], K;

int main(){
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 2;
    for(int i = 4; i <= 76; i++){
        arr[i] = arr[i-2] + arr[i-3];
    }
    while(cin >> K){
        cout << arr[K] << endl;
    }
}
