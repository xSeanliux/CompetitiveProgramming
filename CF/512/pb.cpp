#include <iostream>
#include <math.h>
using namespace std;
int n, d;
int m, x, y;

int main(){
    cin >> n >> d >> m; //(0, d), (d, 0), (n, n-d), (n-d, n)
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        if(x > n || y > n){
            cout << "NO" << endl;
        } else {
            if(abs(x - y) <= d && x + y <= 2*n-d && x + y >= d){ //above x - y = -d and below x - y = d
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}
