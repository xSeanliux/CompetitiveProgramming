#include <iostream>
#include <vector>
#define ulli unsigned long long int
#define ull unsigned long long int
using namespace std;

ulli T, a, b, n;



int modexp(ulli b, ulli e, ulli m){
    if(!e) return 1;
    if(e == 1) return b % m;
    ulli res = (ulli)modexp(b, e/2, m);
    res = ((ulli)res * (ulli)res) % m;
    if(e % 2) res = (res * b) % m;
    return (int)res;
}


int main(){
    scanf("%llu", &T);
    while(T--){
        scanf("%llu%llu%llu", &a, &b, &n);
        vector<ulli> f;
        int peri;
        f.push_back(0);
        f.push_back(1%n);
        for(int i = 2;;i++){
            f.push_back((f[i-1] + f[i-2])%n);
            //cout << i << ": " << f[i] << endl;
            if(f[i] == f[1] && f[i-1] == f[0]) {
                peri = i - 1;
                break;
            }
        }
        //cout << "PERI " << peri << endl;
        //cout << pow_mod(a, b, (ulli)peri) << endl;
        printf("%llu\n", f[ modexp(a%peri, b, (ulli)peri) ]);
    }
}
