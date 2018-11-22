#include <iostream>
using namespace std;

void qs(int arr[], int left, int right){
    if(left >= right) return;
    int pivot = arr[left];
    int left_counter = left;
    for(int i = left ; i <= right; i++ ){
        if(arr[i] <= pivot){
            swap(arr[i], arr[left_counter]);
            left_counter++;
        }
    }
    swap(arr[left], arr[left_counter-1]);
    qs(arr, left, left_counter-2);
    qs(arr, left_counter, right);


}

int main(){
    int N;
    while(cin >> N){
        int arr[N];
        for(int i = 0 ; i < N ;i++){
            cin >> arr[i];
        }
        qs(arr, 0, N-1);

        cout << arr[0];
        for(int i = 1; i < N; i++){
            cout << " " << arr[i];
        }
        cout << endl;


        if(arr[0] >= 60){
            cout << "best case" << endl;
        } else {
            for(int i = N-1; i >= 0; i--){
                if(arr[i] < 60){
                    cout << arr[i] << endl;
                    break;
                }
            }
        }

        if(arr[N-1] < 60){
            cout << "worst case" << endl;
        } else {
            for(int i = 0; i < N; i++){
                if(arr[i]>= 60){
                    cout << arr[i] << endl;
                    break;
                }
            }
        }
    }



}
