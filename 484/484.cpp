#include <iostream>
#include <string.h>
using namespace std;

int N, head = 0, MAX = 1000000;

struct Num{
    int val;
    int times;
};

Num arr[1000000];

int alreadyMade(int N){
    for(int i = 0; i < head; i++){
        if(arr[i].val == N) return i;
    }
    return -1;
}

int main(){
    for(int i = 0 ; i < MAX ; i++){
        arr[i].times = 0;
    }
    while(cin >> N){
        int res = alreadyMade(N);
        if(res == -1){
            arr[head].val = N;
            arr[head].times = 1;
            head++;
        } else {
            arr[res].times++;
        }


    }
    for(int i = 0; i < head; i++){
        //if(i) printf("\n");
        printf("%d %d\n", arr[i].val, arr[i].times);
    }
}
