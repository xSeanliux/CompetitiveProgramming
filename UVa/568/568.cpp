#include <iostream>
using namespace std;

unsigned long long int ans[10000 + 1], N;

void getAns(){
    ans[0] = 1;
    unsigned long long int res;
    for(int i = 1; i <= 10000; i++){
        res = (ans[i-1] * i);
        while(!(res % 10)) res /= 10;
        ans[i] = (res) % 100000;
    }
}

int main(){
    getAns();
    while(cin >> N){
        printf("%5d -> %d\n", N, ans[N]%10);
    }
}
