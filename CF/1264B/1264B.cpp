#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

int a, b, c, d, n;
string fr = "", bk = "";

int abs(int x){
    return x < 0 ? -x : x;
}

int main(){
    cin >> a >> b >> c >> d;
    if(a > b){
        if(!c && !d && a == b + 1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            return 0;
        }
        cout << 0;
        for(int i = 0; i < b; i++){
            cout << " 1 0";
        }
        cout << endl;
        return 0;
    } else if(d > c){

        if(!a && !b && c + 1 == d){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            return 0;
        }
        cout << 3;
        for(int i = 0; i < c; i++){
            cout << " 2 3";
        }
        cout << endl;
        return 0;
    }
    if(a > b || d > c || abs((b - a) - (c - d)) > 1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < a; i++){
        fr += "01";
    }
    for(int i = 0; i < d; i++){
        bk += "23";
    }
    b -= a;
    c -= d;
    int k = min(b, c);
    for(int i = 0; i < k; i++){
        fr += "21";
    }
    b -= k;
    c -= k;
    //cout << "b = "<< b << ", c = " << c << endl;
    if(b == 1) fr = "1" + fr;
    if(c == 1) bk = bk + "2";
    for(char c : fr) cout << c << " ";
    for(char c : bk) cout << c << " ";
    cout << endl;
}
