#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;


int h, m, ha, ma, c;
string com;


int main(){
    cin >> c;
    for(int i = 0 ; i < c; i++){
        cin >> com;
        h = stoi(com.substr(0, 2));
        m = stoi(com.substr(3));
        ha = (h%12)*30;
        ma = m*6;
        ha = 360 - ha;
        ma = 360 - ma;
        h = ha/30;
        m = ma/6;
        if(m == 60) m = 0;
        if(m > 0) h -= 1;
        if(!h) h = 12;
        printf("%02d:%02d\n", h, m);
    }
}
