#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d;
int N = 0;
int main()
{
    while(cin >> a >> b >> c >> d){
        if(N == 0){
            N++;
        } else {
            cout << endl;
        }
        if(!a) return 0;
        if(a == c || b == d){
            if(a == c && b == d){
                cout << 0;
            } else {
                cout << 1;
            }
        } else {
            if(a + b == c + d || a - b == c - d) cout << 1;
            else cout << 2;
        }
    }
}
