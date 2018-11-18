#include <iostream>
using namespace std;

int cases, a, b;

int main(){
    cin >> cases;
    for(int i = 1; i <= cases; i++){
        cin >> a >> b;
        if(a % 2 == 0){
            a++;
        }
        if(b % 2 == 0){
            b--;
        }
        int S = (a + b)*(b - a + 2)/4;
        cout << "Case " << i << ": " << S << endl;
    }
}
