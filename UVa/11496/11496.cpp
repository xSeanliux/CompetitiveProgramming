#include <iostream>
using namespace std;

int l, n[10000 + 5], p;

int mod(int N){
    if(N < 0)
        return N + l;
    else if(N >= l)
        return N - l;
    return N;
}


int main(){
    while(cin >> l){
        if(!l) return 0;
        for(int i = 0 ; i < l; i++){
            cin >> n[i];
        }
        p = 0;
        for(int i = 0; i < l; i++){
            if((n[i] > n[mod(i + 1)] && n[i] > n[mod(i - 1)]) || (n[i] < n[mod(i + 1)] && n[i] < n[mod(i - 1)])){
                p++;
            }
        }
        printf("%d\n", p);
    }
}
