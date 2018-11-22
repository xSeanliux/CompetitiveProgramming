#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

string m, n;
long long int ans;

int main(){
    while(cin >> m >> n){
        if(m == "0" && n == "0"){
            return 0;
        } else {
            int l1 = m.length();
            int l2 = n.length();
            int M = stoi(m.substr(l1-1));
            int N;
            if(l2 >= 10){
                N = stoi(n.substr(l2-2));
            } else {
                N = stoi(n);
            }
            if(M == 1 || M == 6 || M == 5){
                ans = M;
            } else if(M == 4 || M == 9){
                ans = pow(M + 0.0, (N % 2));
                if(!(N % 2)){
                    ans = pow(M + 0.0, 2.0);
                }
            } else {
                ans = pow(M + 0.0, (N % 4));
                if(!(N % 4)){
                    ans = pow(M + 0.0, 4.0);
                }
            }
            //cout << M << " " << N << endl;

            cout << ans % 10 << endl;
        }
    }
}
