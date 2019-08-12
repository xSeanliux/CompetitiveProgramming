#include <iostream>
#include <string>
using namespace std;

int T;
string s;
int fail[6005];

void getFail(){
    fail[0] = -1;
    for(int i = 1; i < s.length(); i++){
        int q = fail[i-1];
        while(q > 0 && s[q + 1] != s[i])
            q = fail[q];
        if(s[q + 1] == s[i]) fail[i] = q + 1;
        else fail[i] = q;
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> s;
        getFail();
        cout << "Starting from " << fail[s.length() - 1] + 1 << endl;
        for(int i = 1; i <= 8; i++){
            cout << s[(fail[s.length() - 1] + i) % s.length()];
        }
        cout << "..." << endl;
    }
}
