#include <iostream>
using namespace std;

int t, n, a, b, x;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        bool fhas = false;
        for(int i = 0; i < a; i++){
            cin >> x;
            if(x == n) fhas = true;
        }
        for(int i = 0; i < b; i++){
            cin >> x;
            if(x == n) fhas = false;
        }
        if(fhas) cout << "YES" << endl;
        else cout << "NO" <<endl;
    }
}
