#include <iostream>
using namespace std;

int a, b, c;
long long int sum;

int main(){
    cin >> c;
    for(int k = 0; k < c; k++){
        cin >> a >> b;
        long long int ans = a * (a+1) / 2 - (a - b + 1) * (a - b + 2) / 2;
        cout << ans << endl;
    }
}
