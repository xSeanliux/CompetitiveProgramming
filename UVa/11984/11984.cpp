#include <iostream>
using namespace std;

float c, C, dF;

int main(){
    cin >> c;
    for(int i = 1; i <= c; i++){
        cin >> C >> dF;
        C += (dF) * 5 / 9;
        printf("Case %d: %.2f\n", i, C);
    }
}
