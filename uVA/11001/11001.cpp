#include <iostream>
#include <math.h>
using namespace std;

long long int a, b;

double len(int k){
    return 0.3*k*sqrt((a+0.0)/k - b);
}


int main(){
    while(cin >> a >> b){
        if(!a) return 0;
        if(a % (2*b)){
            int ce = ceil(a/2.0/b);
            int fl = floor(a/2.0/b);
            //cout << "ce, fl = " << ce << ", " << fl << endl;
            //printf("%.9f, %.9f\n", len(ce), len(fl));
            //cout << len(ce) - len(fl) << endl;
            if(abs(len(ce) - len(fl)) < 0.000001){
                cout << 0 << endl;
            } else
                cout << ( (len(ce) > len(fl)) ? ce : fl ) << endl;
        }
        else
            cout << a/2/b << endl;
    }
}
