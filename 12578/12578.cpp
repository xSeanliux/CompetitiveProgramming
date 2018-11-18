#include <iostream>
#include <math.h>
using namespace std;


double PI = acos(-1), c, L;

int main(){
    cin >> c;
    for(int k = 0; k < c; k++){
        if(k)
        cin >> L;
        printf("%.2f %.2f\n", PI*L*L/25, L*L*(0.6 - PI/25));
    }
}


