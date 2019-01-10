#include <iostream>
using namespace std;

long long int N, a, b, x, y;

int main(){
    cin >> N;
    a = 0, b = 0;
    for(int i = 0; i < 2*N; i++){
        cin >> x >> y;
        a += x;
        b += y;
    }
    cout << a/N << " " << b/N << endl;
}
