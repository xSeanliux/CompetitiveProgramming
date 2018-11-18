#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a, b ,c, ans1, ans2;
    while(cin >> a >> b >> c){
        int d  = b*b - 4*a*c;
        if(d > 0){
            ans1 = (-b + sqrt(d))/(2*a);
            ans2 = (-b - sqrt(d))/(2*a);
            //Two different roots x1=?? , x2=??
            cout << "Two different roots x1=" << ans1 <<" , x2="<< ans2 << endl;
        } else if (d == 0){
            ans1 = (-b)/(2*a);
            cout << "Two same roots x=" << ans1 << endl;
        } else if (d < 0){
            cout << "No real root" << endl;
        }
    }

}
