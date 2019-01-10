#include <iostream>
#include <string.h>
using namespace std;

int N;
string s;

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}

struct Frac{
    unsigned long long int num;
    unsigned long long int denom;
};

int main(){
    cin >> N;
    while(N--){
        cin >> s;
        Frac L, R, M;
        L.num = R.denom = 0;
        L.denom = R.num = 1;
        M.num = (L.num + R.num);
        M.denom = (L.denom + R.denom);
        int l = s.length();
        for(int i = 0 ; i < l; i++){
            if(s[i] == 'L'){
                R.num = M.num;
                R.denom = M.denom;
            } else if(s[i] == 'R'){
                L.num = M.num;
                L.denom = M.denom;
            }
            M.num = (L.num + R.num);
            M.denom = (L.denom + R.denom);
            //M.num /= gcd(M.num, M.denom);
            //M.denom /= gcd(M.num, M.denom);
            //cout << "R: " << R.num << "/" << R.denom << ", L: " << L.num << "/" << L.denom << endl;
            //cout << "Am now at " << M.num << "/" << M.denom << endl;
        }
        printf("%lld/%lld\n", M.num, M.denom);
    }
}
