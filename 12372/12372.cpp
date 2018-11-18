#include <iostream>
using namespace std;

int t;

int a, b, c;

int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> a >> b >> c;
        if(a <= 20 && b <= 20 && c <= 20){
            printf("Case %d: good\n", i);
        } else {
            printf("Case %d: bad\n", i);
        }
    }
}
