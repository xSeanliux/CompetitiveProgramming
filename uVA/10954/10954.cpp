#include <iostream>
using namespace std;

int n;

int arr[5005];

int main(){
    while(cin >> n){
        if(!n) return 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int N = n - 1;

        sort(arr, arr + n);
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        int tCost = N * arr[0];
        for(int i = 1; i < n; i++){
            tCost += arr[i] * (n - i);
        }
        printf("%d\n", tCost);
    }

}
