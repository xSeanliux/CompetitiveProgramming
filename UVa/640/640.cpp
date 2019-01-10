#include <iostream>
using namespace std;

bool isSelf[1000000 + 5];

int next(int N){
    int ans = N;
    while(N > 0){
        ans += N % 10;
        N = (N - N % 10)/10;
    }
    return ans;
}

void go(){
    for(int i = 0 ; i <=  1000000; i++){
        isSelf[i] = true;
    }
    for(int i = 1 ; i <=  1000000; i++){
        if(isSelf[i]){
            cout << i << endl;
            int k = next(i);
            while(k <=  1000000 && isSelf[k]){
                isSelf[k] = false;
                k = next(k);
            }
        }
    }
}

int main(){
    go();
}
