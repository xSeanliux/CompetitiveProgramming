#include <iostream>
using namespace std;

const int maxN = 1e6 + 10;

int n;
bool canDo[maxN];

int main(){
    int a = 1, b = 2, _a, _b;
    while(max(a, b) <= maxN){
        canDo[a] = true;
        canDo[b] = true;
        if(a % 2) swap(a, b); //a is even!
        _a = a + a + 1;
        _b = b + a + 1;
        swap(a, _a);
        swap(b, _b);
    }
    cin >> n;
    cout << canDo[n] << endl;
}
