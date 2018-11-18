#include <iostream>
using namespace std;

int c, n;

int arr[100];

int main(){
    cin >> c;
    for(int is = 1; is <= c ; is++){
        cin >> n;
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
        }
        cout << "Case " << is << ": ";
        if(n % 2 == 0){
            cout << arr[n/2] << endl;
        } else {
            cout << arr[(n-1)/2] << endl;
        }
    }
}
