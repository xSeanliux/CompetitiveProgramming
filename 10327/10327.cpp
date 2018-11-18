#include <iostream>
using namespace std;

int arr[1000 + 5];
int main(){
    int len;
    while(cin >> len){
        for(int i = 0; i < len; i++){
            cin >> arr[i];
        }
        int swaps, totalswaps = 0;
        do{
            swaps = 0;
            for(int i = 0; i < len-1; i++){
                if(arr[i] > arr[i+1]){
                    swap(arr[i], arr[i+1]);
                    swaps++;
                    totalswaps++;
                }
            }
        }while(swaps);
        cout << "Minimum exchange operations : " << totalswaps << endl;

    }
}
