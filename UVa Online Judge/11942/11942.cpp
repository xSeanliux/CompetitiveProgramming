#include <iostream>
using namespace std;

int c, arr[15];

int main(){
    cin >> c;
    printf("Lumberjacks:\n");
    for(int ia = 0; ia < c; ia++){
        for(int i = 0; i < 10; i++){
            cin >> arr[i];
        }
        int diff = ((arr[0] - arr[1]) > 0) ? 1 : 0;
        bool canGo = true;
        if(diff){
            for(int i = 0 ; i < 9; i++){
                if(arr[i+1] - arr[i] > 0){
                    canGo = false;
                    break;
                }
            }
        } else {
            for(int i = 0 ; i < 9; i++){
                if(arr[i+1] - arr[i] < 0){
                    canGo = false;
                    break;
                }
            }
        }
        if(canGo){
            cout << "Ordered" << endl;
        } else {
            cout << "Unordered" << endl;
        }
    }
}
