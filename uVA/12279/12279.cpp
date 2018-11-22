#include <iostream>
using namespace std;

int N, n, a, c;

int main(){
    c = 1;
    while(cin >> N){
        if(!N) return 0;
        a = 0;
        for(int i = 0; i < N; i++){
            cin >> n;
            if(!n){
                a--;
            } else {
                a++;
            }
        }
        printf("Case %d: %d\n", c, a);
        c++;
    }

}
