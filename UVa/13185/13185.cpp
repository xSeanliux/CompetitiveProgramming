#include <iostream>
using namespace std;


int n, c;

int f(int n){
    int s = 0;
    for(int i = 1; i < n; i++){
        if(!(n % i)) s += i;
    }
    return s;
}

int main(){
    cin >> c;
    for(int i = 0 ;i < c; i++){
        cin >> n;
        int r = f(n);
        if(n == r){
            printf("perfect\n");
        } else if(n < r){
            printf("abundant\n");
        } else if(n > r){
            printf("deficient\n");
        }
    }
}

