#include <iostream>
#include <algorithm>
using namespace std;

float sum, arr[10], c;

int main(){
    cin >> c;
    for(int k = 1; k <= c; k++){
        printf("Case %d: ", k);
        sum = 0;
        for(int i = 0; i < 7; i++){
            cin >> arr[i];
            if(i < 4) sum += arr[i];
        }
        sort(arr + 4, arr + 7);
        sum += (arr[5] + arr[6])/2;
        if(sum >= 90){
            printf("A\n");
        } else if(sum >= 80){
            printf("B\n");
        } else if(sum >= 70){
            printf("C\n");
        } else if(sum >= 60){
            printf("D\n");
        } else {
            printf("F\n");
        }
    }
}
