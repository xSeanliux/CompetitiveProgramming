#include <iostream>
using namespace std;

int q;
long long int n, m;

int main(){
    cin >> q;
    while(q--){
        cin >> n >> m;
        n /= m;
        long long int z = n/10, t = 0, a = 0;
        for(int i = 0; i < 10; i++){
            t += (i * m) % 10;
        }
        //3 + 6 + 9 + 2 + 5 + 8 + 1 + 4 +
        a += t * z;
        for(int i = 1; i <= n % 10; i++){
            a += (i * m) % 10;
        }
        cout << a << endl;
    }
}
