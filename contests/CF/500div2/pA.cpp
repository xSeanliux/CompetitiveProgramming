#include <iostream>
using namespace std;

int N, t, sum1, sum2;

int main(){
    cin >> N;
    sum1 = sum2 = 0;
    for(int i = 0 ; i < N; i++){
        cin >> t;
        sum1 += t;
    }
    for(int i = 0 ; i < N; i++){
        cin >> t;
        sum2 += t;
    }
    if(sum1 >= sum2){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
