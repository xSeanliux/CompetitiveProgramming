#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

double s, n, a, b;

string add;




int main(){
    cin >> s;
    for(int k = 0 ; k < s; k++){
        cin >> n;
        n;
        a = pow(2, n-1);
        if(n <= 5) printf("%.0f\n", a);
        else {
            a = n*(n-1)/2;
            b = n*(n-1)*(n-2)*(n-3)/24;
            printf("%.0f\n", a + b + 1);
        }
    }
}
