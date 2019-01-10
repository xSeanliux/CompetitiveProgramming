#include <iostream>
#include <string.h>
using namespace std;
int c, a, b;
string s;

int main(){
    cin >> c;
    for(int ak = 1; ak <= c; ak++){
        cin >> a >> b;
        for(int i = 0; i < a + b; i++){
            cin >> s;
        }
        printf("Case %d: %d\n", ak, a*b);
    }
}
