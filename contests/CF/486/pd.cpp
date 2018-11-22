#include <iostream>
#include <math.h>
#include <set>
using namespace std;

set <long long int> arr;
int N, k;
int a, b, c, sols;
int main(){
    cin >> N;
    sols = 0;
    long long int ar[N];
    arr.clear();
    for(int i = 0; i < N; i++){
        cin >> ar[i];
        arr.insert(ar[i]);
    }
    for(int i = 0 ; i < N; i++){
        for(long long int j = 1; j <= 2147483648; j*=2){
            //cout << "checking: " << ar[i] + pow(2, j) << " and " << ar[i] - pow(2, j) << endl;
            if(arr.count(ar[i] + j) && arr.count(ar[i] - j)){
                cout << 3 << endl;
                cout <<ar[i] + j << " " << ar[i] << " " << ar[i] - j << endl;
                return 0;
            }
        }
    }
    for(int i = 0 ; i < N; i++){
        for(long long int j = 1; j <= 2147483648; j*=2){
            if(arr.count(ar[i] + j)){
                cout << 2 << endl;
                cout << ar[i] + j << " " << ar[i] << endl;
                return 0;
            } else if(arr.count(ar[i] - j)){
                cout << 2 << endl;
                cout << ar[i] - j << " " << ar[i] << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    cout << ar[0] << endl;
    return 0;

}
