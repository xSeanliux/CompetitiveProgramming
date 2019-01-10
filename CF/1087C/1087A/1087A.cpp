#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    cin >> s;
    int l = s.length(), cI, k = -1;
    if(l % 2){
        cI = l/2;
    } else {
        cI = l/2 - 1;
    }
    for(int i = 0; i < l; i++){
        cI += k * i;
        cout << s[cI];
        k *= -1;
    }
    cout << endl;
}
