#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        double low = 0;
        double high = n;
        double mid = (low + high) / 2;
        double error = 10000;
        while(fabs(mid * mid - n) > 0.0001){

            if(mid * mid > n){ //mid is too big
                high = mid;
            } else if(mid * mid < n){
                low = mid;
            } else if(mid * mid == n){
                break;
            }
        mid = (low + high) / 2;

            error = mid * mid - n;
            //cout << "High: " << high << ", Low: " << low << endl;
            //cout << "Found: " << mid << " ^2  = " << mid * mid << ", error: " << error << "%. " << endl;
        }

        cout << "Final Found: " << mid << " ^2  = " << mid * mid << ", error: " << error << "%. " << endl;
    }
}
