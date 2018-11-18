#include <iostream>
using namespace std;

void ms(int arr[], int left, int right){
    if(right - left <= 1){
        return;
    } else {
        int mid  = (left + right)/2;
        ms(arr, left, mid-1);
        ms(arr, mid, right);
        int sortedArr[right - left + 1];
        int r = mid, l = left, ci = 0;
        while(r <= right && l < mid){
            if(arr[l] < arr[r]){
                sortedArr[ci] = arr[l];
                l++;
                ci++;
            } else if(arr[r] <= arr[l]){
                sortedArr[ci] = arr[r];
                r++;
                ci++;
            }


        }
        if(r <= right){
            while(r <= right){
                sortedArr[ci] = arr[r];
                r++;
                ci++;
            }
        } else if(l < mid){
            while(l < mid){
                sortedArr[ci] = arr[l];
                l++;
                ci++;
            }
        }
        for(int i = left, ci = 0; i <= right; i++, ci++){
            arr[i] = sortedArr[ci];
        }


    }


}


int main(){
    int arr[100];
    int N;
    while(cin >> N){
        for(int i = 0 ; i < N && i < 100; i++){
            cin >> arr[i];
        }
        ms(arr, 0, N-1);
        for(int i = 0 ; i < N && i < 100; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

    }

}
