#include <iostream>
using namespace std;

int selectionSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        for(int ii = i+1; ii < len; ii++){
            if(arr[i] > arr[ii]){
                int tmp = arr[i];
                arr[i] = arr[ii];
                arr[ii] = tmp;
            }
        }
    }

    //output
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


}




int main(){

    int len;
    while(cin >> len){
        int arr[len];
        for(int i = 0; i < len; i++){
            cin >> arr[i];
        }
        selectionSort(arr, len);


    }



}
