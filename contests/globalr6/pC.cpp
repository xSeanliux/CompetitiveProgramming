#include <iostream>
using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int r, c, ans[505][505], ver[505], hor[505];

int main(){
    cin >> r >> c;
    if(r == 1 && c == 1){
        cout << 0 << endl;
        return 0;
    }
    int cnt = 1;
    if(r < c){
        for(int i = 1; i <= r; i++) hor[i] = i;
        for(int i = 1; i <= c; i++) ver[i] = i + r;
    } else {
        for(int i = 1; i <= r; i++) hor[i] = i + c;
        for(int i = 1; i <= c; i++) ver[i] = i;
    }
    //for(int i = 1; i <= r; i++) cout << "hor[" << i << "] = " << hor[i] << endl;
    //for(int i = 1; i <= c; i++) cout << "ver[" << i << "] = " << ver[i] << endl;
    for(int i = 1; i <= r; i++){
        //cout << "hor[" << i << "] = " << hor[i] << endl;
        for(int j = 1; j <= c; j++){
            cout << lcm(hor[i], ver[j]) << " \n"[j == c];
        }
    }
}
