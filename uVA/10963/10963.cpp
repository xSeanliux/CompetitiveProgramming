#include <iostream>
using namespace std;

int c, n, a, b;

int main(){
    cin >> c;
    for(int k = 0; k < c; k++){
        if(k > 0) cout << endl;
        cin >> n;
        bool flag = true;
        cin >> a >> b;
        int diff = a - b;
        for(int j = 1; j < n; j++){
            cin >> a >> b;
            if(a - b != diff){
                flag = false;

            }
        }
        if(flag){
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << endl;
    }
}
