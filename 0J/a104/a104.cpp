#include <iostream>
#include <array>
using namespace std;
int arr[1006]; //max 1000;
void qs(int arr[], int left, int right){
    if(left >= right) return;

    int pivot = arr[left];
    int left_counter = left;
    for(int i = left; i <= right; i++){
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
    int len;
    while(scanf("%d", &len) != EOF){

        for(int i = 0; i < len; i++){
            scanf("%d", &arr[i]);
        }

        qs(arr, 0, len-1);

        for(int i = 0; i < len; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
