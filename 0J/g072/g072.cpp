#include <iostream>
using namespace std;

int n, k, cases;

int f(int N){
    if(N <= 1){
        return 1;
    } else {
        return f(N-1) * N;
    }
}

int main(){
    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> n >> k;
        n--;
        k--;
        int result = f(n)/(f(n-k)*f(k));

        cout <<  result << endl;
    }

}
