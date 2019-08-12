#include <iostream>
using namespace std;

int N, M;
int main(){
    cin >> N >> M;
    if(N <= 32) cout << (M % (1LL << N)) << endl;
    else cout << M << endl;
}
