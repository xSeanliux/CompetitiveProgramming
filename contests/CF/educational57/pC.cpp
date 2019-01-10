#include <iostream>
using namespace std;

int deg, C;

int main(){
    cin >> C;
    while(cin >> deg){
        for(int n = 3; n <= 998244353; n++){
            if(!(deg*n*(n-2) % ((n-2)*180)) && (deg*n*(n-2) / ((n-2)*180)) < (n-1)){
                cout << n << endl;
                break;
            } else if(n == 998244353){
                cout << -1 << endl;
            }
        }

    }
}
