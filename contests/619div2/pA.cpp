#include <iostream>
#include <string.h>
#include <vector>
#define int long long int
using namespace std;

int N;
string a, b, c;

signed main(){
    cin >> N;
    while(N--){
        cin >> a >> b >> c;
        int l = a.length();
        bool f = true;
        for(int i = 0; i < l; i++){
            if(!(a[i] == c[i] || b[i] == c[i])){
                cout << "NO" << endl;
                f = false;
                break;
            }
        }
        if(f) cout << "YES" << endl;
    }
}
