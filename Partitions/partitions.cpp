#include <iostream>
using namespace std;

void run(int n, int maximum){
    if(n == 0){ //if n == maximum
        cout << endl;
        return;
    }

    for(int i = min(maximum, n); i >= 1; i--){
        cout << "i: " << i <<" , n-i = " << n-i << endl;
        //cout << " + " << i << endl;
        cout << "running (" << n-i << ", " << i << ")" << endl;
        run(n-i, i);
    }

}


int main(){
    int N;
    while(cin >> N){
        run(N, N);
    }
}
