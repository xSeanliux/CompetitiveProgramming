#include<iostream>
#include <math.h>
using namespace std;

int main(){
    int num, base, counter = 0, bit , nextnum, orinum; //from base 10 to base X
    double ans;
    while(cin >> num >> base){
        orinum = num;
         while(num > 0){
            cout << "bit = " << num << " % " << base << " = " << num % base << endl;
            bit = num % base;
            cout << "nextnum = " << num << " / " << base << " = " << num/base << endl;
            nextnum = num / base;
            ans += bit;
            ans/=10;
            counter++;
            num = nextnum;
        }
        cout << orinum << " in base " << base << " is " << (double)ans*pow(10,counter)<< endl;
    }

}
