#include <iostream>
using namespace std;


int N;

int f(int n){
    int s = 0;
    for(int i = 1; i < n; i++){
        if(!(n % i)) s += i;
    }
    return s;
}
int n;
int main(){
    printf("PERFECTION OUTPUT\n");
    while(cin >> n){
        if(!n) {
            printf("END OF OUTPUT\n");
            return 0;
        }
        printf("%5d  ", n);
        int r = f(n);
        if(n == r){
            printf("PERFECT\n");
        } else if(n < r){
            printf("ABUNDANT\n");
        } else if(n > r){
            printf("DEFICIENT\n");
        }
    }
}
