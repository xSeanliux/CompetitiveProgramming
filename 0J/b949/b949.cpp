#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int N;
    double ans = 42;
    while(cin >> N !=EOF) {

        ans = pow(N, 2)*25;
        //cout << ans << endl;
        printf("%d", ans);

    }
}
