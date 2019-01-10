#include <iostream>
#include <string.h>
using namespace std;

int N, K, C;

int mod(int a, int b){
    while(a < 0) a += b;
    return a % b;
}

int main(){
    cin >> C;
    while(C--){
        cin >> N >> K;
        int nums[N];
        bool canDo[K], canDoNow[K];
        memset(canDo, false, K);
        memset(canDoNow, false, K);
        for(int i = 0 ; i < N; i++){
            cin >> nums[i];
            nums[i] = mod(nums[i], K);
            //cout << "nums[" << i << "] = " << nums[i] << endl;
        }
        canDo[nums[0]] = true;
        //cout << "canDo[" << nums[0] << "] = true" << endl;
        for(int i = 1 ; i < N; i++){
            int toDo = nums[i];
            //cout << "checking " << toDo << endl;
            for(int j = 0; j < K; j++){
                if(canDo[j]) {
                    canDoNow[mod(j + toDo, K)] = true;
                    canDoNow[mod(j - toDo, K)] = true;
                    //cout << "canDo[" << mod(j - toDo, K) << "] = true" << endl;
                    //cout << "canDo[" << mod(j + toDo, K) << "] = true" << endl;
                }
            }
            for(int j = 0 ; j < K; j++){
                canDo[j] = canDoNow[j];
            }
            memset(canDoNow, false, K);
        }
        if(canDo[0])
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;

    }
}
