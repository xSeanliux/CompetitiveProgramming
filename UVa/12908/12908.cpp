#include <iostream>
using namespace std;

double s;

int main(){
    while(cin >> s){
        if(!s) return 0;
        //cout << "S: " << s << endl;
        double l = 1;
        double u = 1000000;
        double m = (int)(l + u)/2;
        double k = (m*(m+1))/2;
        double oris = s;
        while(k < s || (k > s && k - s > m) || k - s == 0){
            if(k < s || k - s == 0){
                l = m;
            }if(k > s && k - s > m){
                u = m;
            }
            m = (int)(l + u)/2;
            k = (m*(m+1))/2;
            //cout << m << " " << k << endl;
        }
        printf("%.0f %.0f\n", k-oris,m);
    }
}
