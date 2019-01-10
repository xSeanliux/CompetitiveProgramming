#include <iostream>
using namespace std;

int h, w, k;

int main(){
    cin >> h >> w >> k;
    printf("%d\n", 2*(k*(w + h) - 2*k - 4*k*(k-1)));
}
