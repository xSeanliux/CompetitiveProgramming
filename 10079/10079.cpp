#include <iostream>
using namespace std;
long double n;
int main(){
    while(cin >> n){

        if(n < 0){
            return 0;
        } else {
            long double ans = (n + n*n)/2 + 1;
            cout << fixed << ans << endl;
            printf("%.0Lf\n", ans);
        }
    }
}
