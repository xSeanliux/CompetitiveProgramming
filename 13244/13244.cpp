#include<iostream>
using namespace std;

long long int c, N;

int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> N;
        long long int ans = ((N*N)+1)/2;
        printf("%lld\n", ans);
    }
}
