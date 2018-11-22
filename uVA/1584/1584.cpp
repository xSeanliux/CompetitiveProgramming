#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string minStr, s;
int c;

int main(){
    cin >> c;
    for(int ia= 0 ; ia < c; ia++){
        cin >> s;
        minStr = s;
        int l = s.length();
        char z;
        for(int i = 0; i < l; i++){
            s = s.substr(1) + s[0];
            if(s < minStr) minStr = s;
        }
        cout << minStr << endl;
    }
}


