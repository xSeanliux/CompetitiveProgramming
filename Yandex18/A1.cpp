#include <iostream>
using namespace std;

int h, m;

int main(){
    while(cin >> h >> m){
        int t1 = h * 30;
        t1 = 360 - t1;
        int t2 = m * 6;
        t2 = 360 - t2;
        printf("%d %d\n", (t1/30)%12, (t2/6)%60);
    }
}
