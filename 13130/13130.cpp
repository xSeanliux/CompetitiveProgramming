#include <iostream>
using namespace std;
int arr[10], c;

int main(){
    cin >> c;
    for(int ia = 0 ; ia < c; ia++){
        for(int i = 0 ; i < 5; i++){
            cin >> arr[i];
        }
        bool isGood = true;
        for(int i = 1; i < 5; i++){
            if(arr[i] - arr[i-1] != 1){
                isGood = false;
                break;
            }
        }
        if(isGood){
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}
