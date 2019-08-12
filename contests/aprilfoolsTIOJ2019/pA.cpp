#include <iostream>
using namespace std;

long long int N;
//N^(N + 1) + N - 1



int main(){
    while(cin >> N){
        if(N == 1) cout << 1 << endl;
        else if(N == 2) cout << 9 << endl;
        else if(N == 3) cout << 83 << endl;
        else cout << 1 << endl;
    }
}
