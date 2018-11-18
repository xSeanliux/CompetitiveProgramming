#include <iostream>
using namespace std;

bool arr1[5], arr2[5];

int main(){
    while(cin >> arr1[0] >> arr1[1] >> arr1[2] >> arr1[3] >> arr1[4]){
        cin >> arr2[0] >> arr2[1] >> arr2[2] >> arr2[3] >> arr2[4];
        if(arr1[0] != arr2[0] && arr1[1] != arr2[1] && arr1[2] != arr2[2] && arr1[3] != arr2[3] && arr1[4] != arr2[4]){
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}
