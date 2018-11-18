#include <iostream>
#include <math.h>
using namespace std;

int f(int N){
    //cout << "Running N = " << N << endl;
    if(N < 10){
        return N;
    } else {
        int k = N, s = 0;
        while(k > 0){
            int l = k%10;
            //cout << "adding: " << l << endl;
            s += k%10;
            k = floor(k/10);
        }
        return f(s);
    }

}

int main(){
    int N;
    while(cin >> N){
        if(N){
            cout << f(N) << endl;
        } else {
            return 0;
        }
    }

}
