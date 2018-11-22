#include <iostream>
using namespace std;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}


unsigned long long int n, m, k;
bool isDoable = true;
int main(){
    cin >> n >> m >> k; //(0, 0), (a, 0), (0, b)
    if((2*n*m % k) > 0) {isDoable = false;}
    int a = n, b = m;
    int Z;
    if(n == 1){
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << "1 0" << endl;
        cout << "1 " << 2*n*m/k << endl;
    } else if(m == 1){
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << "0 1" << endl;
        cout << 2*n*m/k << " 1" << endl;
    } else {
        while(gcd(a, k) > 1 || gcd(b, k) > 1){
            if(gcd(a, k) > 1){
                Z = gcd(a, k);
                a /= Z;
                k /= Z;
            } else {
                Z = gcd(b, k);
                b /= Z;
                k /= Z;
            }
            //cout << Z << endl;
        }
        cout << "a, b, k = " << a << ", " << b << ", " << k << endl;
        while(k > 1 && isDoable){
            for(int i = 2 ; i <= k; i++){
                if(!(k % i)){
                    if(!(a % i)){
                        a /= i;
                        k /= i;
                    } else if(!(b % i)){
                        b /= i;
                        k /= i;
                    } else {
                        if(k > 1){
                            isDoable = false;
                            break;
                        }
                    }
                    //cout << "a, b, k = " << a << ", " << b << ", " << k << endl;
                }
            }
        }
        if(!isDoable){
            cout << "NO" << endl;
        } else {
            if(a * 2 <= n){
                a *= 2;
            } else {
                b *= 2;
            }
            cout << "YES" << endl;
            cout << "0 0" << endl;
            cout << a << " 0" << endl;
            cout << "0 " << b << endl;
        }
    }


}
