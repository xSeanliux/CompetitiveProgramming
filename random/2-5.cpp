#include <iostream>
using namespace std;

int a, b, c;

int main(){
    while(cin >> a >> b >> c){
        if(a == 0 && b == 0 && c == 0) return 0;
        cout << a/b << ".";
        a %= b;
        for(int i = 0; i < c; i++){
            a *= 10;
            if(i == c-1){
                int k = a/b;
                a %= b;
                a *= 10;
                if(a / b >= 5) k++;
                cout << k;
                break;
            }
            cout << a/b;
            a %= b;
        }
        cout << endl;
    }
}
