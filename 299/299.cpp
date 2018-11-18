#include <iostream>
using namespace std;

int c, l;

int trains[50];

int bs(){
    int r = 0;
    int swaps = 0;
    for(int i = 1; i < l; i++){
        if(trains[i] < trains[i-1]){
            swap(trains[i], trains[i-1]);
            swaps++;
            r++;
        }
    }
    while(swaps > 0){
        swaps = 0;
        for(int i = 1; i < l; i++){
        if(trains[i] < trains[i-1]){
            swap(trains[i], trains[i-1]);
            swaps++;
            r++;
        }
    }
    }
    return r;
}

int main(){
    cin >> c;
    for(int ia = 0; ia < c; ia++){
        cin >> l;
        for(int i = 0; i < l; i++){
            cin >> trains[i];
        }
        printf("Optimal train swapping takes %d swaps.\n", bs());
    }

}
