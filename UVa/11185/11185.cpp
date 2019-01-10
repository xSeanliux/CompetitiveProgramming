#include <iostream>
using namespace std;

long long N;

void f(long long N, int i){
    if(N == 0){
        if(i == 0) {
            cout << 0;
        }
        return;
    } else {
        int r = N%3;
        f((N-r)/3, i+1);
        cout << r;
    }
}

int main(){
    while(cin >> N){
        if(N >= 0){
            f(N, 0);
            cout << endl;
        } else {
            return 0;
        }

    }

}
