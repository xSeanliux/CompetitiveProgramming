#include <iostream>
#include <set>
using namespace std;

int N, C = 0;

int f(int N){
    int ans = 0;
    while(N){
        ans += (N%10)*(N%10);
        N /= 10;
    }
    return ans;
}

int main(){
    cin >> C;
    for(int i = 1; i <= C; i++){
        cin >> N;
        set <int> s;
        int oriN = N;
        bool flag = true;
        while(N != 1){
            if(N == 1){
                break;
            }
            if(s.count(N)){
                flag = false;
                break;
            }
            s.insert(N);
            N = f(N);
        }
        printf("Case #%d: ", i);
        if(flag){
            printf("%d is a Happy number.\n", oriN);
        } else {
            printf("%d is an Unhappy number.\n", oriN);
        }
    }
}
