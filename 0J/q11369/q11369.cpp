#include <iostream>
using namespace std;


int qs(int arr[], int left, int right){
    int pivot = arr[left];
    int left_counter = left;
    if(right <= left){
        return 0;
    } else {
        for(int i = left; i <= right; i++){
            if(arr[i] >= pivot){
                swap(arr[i], arr[left_counter]);
                left_counter++;
            }
        }
        swap(arr[left_counter-1], arr[left]);
    }
    qs(arr, left, left_counter-2);
    qs(arr, left_counter, right);
}


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
    /*
    //output
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    */

}





int main(){
    int cases, noOfItems, total;

    while(cin >> cases){
        for(int i = 0; i < cases; i++){
            total = 0;
            cin >> noOfItems;
            int items[noOfItems];
            for(int i = 0;i < noOfItems; i++){
                cin >> items[i];
            }

            qs(items, 0, noOfItems-1);
            for(int i = 2; i < noOfItems; i+=3){
                total += items[i];
            }
            cout << total << endl;

        }
    }



}


