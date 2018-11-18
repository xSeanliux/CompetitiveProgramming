#include <iostream>
using namespace std;

int insertionSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        for(int j = i+1;  j > 0; j--){
            if(arr[j-1] > arr[j]){

                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;

            } else {
                break;
            }
        }
    }
    //output
    for(int i = 0; i < len; i++){
        cout << arr[i];
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
        insertionSort(arr, len);
    }








}
