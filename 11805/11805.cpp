#include <iostream>
using namespace std;

int c, n, k, p;
int main(){
    cin >> c;

    for(int ca = 1; ca <= c; ca++){
        cin >> n >> k >> p;
        int r = (k + p)%n;
        if(!r) r += n;
        printf("Case %d: %d\n", ca, r);
    }
}
