#include <iostream>
#include <string.h>
using namespace std;

bool played[3][3], xo[3][3];

inline void solve() {
    string s;
    cin >> s;
    int N = 0;
    for(char c : s) {
        N = N * 8 + (c - '0');
    }
    string state = "";
    for(int i = 0; i < 18; i++){
        bool b = (N >> i) & 1;
        if(i < 9) { 
            played[i / 3][i % 3] = b;
        } else {
            int j = i - 9;
            xo[j / 3][j % 3] = b;
        }
    }
    //cout << "played" << endl;
    /*
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cout << played[i][j];
        cout << endl;
    }
    //cout << "xo" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cout << xo[i][j];
        cout << endl;
    }
    */
    //hori
    for(int i = 0; i < 3; i++) {
        bool curplayed = 1;
        bool allSame = 1;
        for(int j = 0; j < 3; j++) {
           curplayed &= played[i][j];
           allSame &= (xo[i][j] == xo[i][0]);
        }
        if(allSame && curplayed) { //1 = X
            if(xo[i][0]) cout << "X wins\n";
            else cout << "O wins\n";
            return;
        }
    }
    //cout << "hori fin" << endl;
    //vert
    for(int i = 0; i < 3; i++) {
        bool curplayed = 1;
        bool allSame = 1;
        for(int j = 0; j < 3; j++) {
           curplayed &= played[j][i];
           allSame &= (xo[j][i] == xo[0][i]);
        }
        if(allSame && curplayed) { //1 = X
            if(xo[0][i]) cout << "X wins\n";
            else cout << "O wins\n";
            return;
        }
    }
    //diag
    bool curplayed = 1;
    bool allSame = 1;
    for(int i = 0; i < 3; i++) {
        curplayed &= played[i][i];
        allSame &= (xo[i][i] == xo[0][0]);
    }
    if(allSame && curplayed) { //1 = X
        if(xo[0][0]) cout << "X wins\n";
        else cout << "O wins\n";
        return;
    }
    curplayed = 1;
    allSame = 1;
    for(int i = 0; i < 3; i++) {
        curplayed &= played[2 - i][i];
        allSame &= (xo[2 - i][i] == xo[0][2]);
    }
    if(allSame && curplayed) { //1 = X
        if(xo[0][2]) cout << "X wins\n";
        else cout << "O wins\n";
        return;
    }
    if((N & ((1 << 9) - 1)) == ((1 << 9) - 1)) {
        cout << "Cat's\n";
    } else {
        cout << "In progress\n";
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
