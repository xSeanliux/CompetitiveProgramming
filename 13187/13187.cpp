#include <iostream>
#include <string>
using namespace std;

long long int N;
int c;
string s;
int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        scanf("%d",&N);
        printf("%lld\n", N*(N+2));
    }
}
