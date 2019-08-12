#include <iostream>
using namespace std;

int n, m, currentCase = 0;
long double ans = 0;

int main(){
    while(cin >> n >> m){
        if(n == 0 && m == 0) return 0;
        ans = 0;
        for(int i = n; i <= m; i++){
            ans += (long double)(1)/i/i;
            //cout << "+ " << (long double)(1)/i/i << endl;
        }
        currentCase++;
        printf("Case %d: %.5Lf\n", currentCase, ans);
    }
}
