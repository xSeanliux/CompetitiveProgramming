#include <iostream>
#include <math.h>
using namespace std;
int p,  q, r,  s,  t,  u;

double f(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s*tan(x) + t * x * x + u;
}

int main(){

    while(cin >> p >> q >> r >> s >> t >> u){
        //cout << f(0.7554) << endl;
        double ans;
        bool flag = (f(0) <= 0);
        bool hasSol = false;
        for(double i = 0; i <= 10000; i++){
            //cout << i/10000 << "  " << f(i/10000) << ": "<< (f(i/10000) <= 0) << endl;
           if(f(i/10000) == 0){
                ans = i/10000;
                hasSol = true;
                break;
           } else if((f(i/10000) <= 0) == !flag){
                hasSol = true;
                for(double j = i - 1; j <= i + 1; j += 0.0001){
                    bool flag2 = (f((j-1)/10000) <= 0);
                    //cout << j/10000 << "  " << f(j/10000) << ": "<< (f(j/10000) <= 0) << endl;
                    if(f(j/10000) == 0){
                        ans = round(j*1000)/10000000;
                        break;

                    }
                    else if((f(j/10000) <= 0) == !flag){
                            ans = round(j*1000)/10000000;
                            break;
                    }
                }
                break;
           }
        }
        if(!hasSol){
            cout << "No solution" << endl;
        } else {
            //cout << ans << endl;
            printf("%.4f\n", ans);
        }

    }

}

