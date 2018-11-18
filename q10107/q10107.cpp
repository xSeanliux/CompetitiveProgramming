#include <iostream>
#include <math.h>
using namespace std;

int insertionSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        for(int j = i;  j > 0; j--){
            if(arr[j-1] > arr[j]){

                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;

            } else {
                break;
            }
        }
    }


    for(int i =0 ; i < len; i++){
        //cout << arr[i] << ", ";
    }
    //cout << endl;
    if(len % 2 == 0){ // odd lol    0 1 2 3 4,
        //cout << (len-1)/2 << " | " << (len+1)/2 << endl;
        cout << (arr[len/2] + arr[len/2-1])/2 << endl; // 0 1 2 3 4 5 len =

    } else { //even lol
        //cout <<"len/2: " << len/2 << endl;
        cout << arr[len/2] << endl;
    }
    //output




}


int main(){

    int arr[10005];
    int len = 0;
    while(cin >> arr[len]){
        //cout <<"arr[len]: " << arr[len] << endl;
        len++;
        insertionSort(arr, len);
        //   0 1 2 3 4 5 6 7

        //cout << "len: " << len << endl;


    }

}
