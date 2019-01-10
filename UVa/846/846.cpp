#include <iostream>
#include <math.h>
using namespace std;

int C, A, B;

int main(){
    cin >> C;
    while(C--){
        cin >> A >> B;
        int R = B - A; //n 2n^2 = 2R //n = [sqrt(R)]
        int n = floor(sqrt(R));
        //cout << "n = " << n << endl;
        if(!R){
            cout << 0 << endl;
            continue;
        }
        int ans;
        if(n == 1){
            ans = R;
        } else {
            int sum = 0;
            /*
            for(int i = 1; i <= n; i++){
                sum += i;
                cout << sum << endl;

            }
            for(int i = n-1; i > 0; i--){
                sum += i;
                cout << sum << endl;

            }
            */
            ans = 2*n - 1;
            if(R - n*n > 0 && R - n*n <= n) ans++;
            else if(R - n*n > n) ans += 2;
        }
        printf("%d\n", ans);
    }
}
