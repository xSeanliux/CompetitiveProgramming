#include <iostream>
#include <string.h>
using namespace std;

string x, y;
int ind = 0, ans[(int)5e5 + 10], fail[(int)5e5 + 10];

void getFail(string s){
    fail[0] = -1;
    for(int i = 1; i < s.length(); i++){
        int q = fail[i - 1];
        while(q >= 0 && s[q + 1] != s[i]){
            q = fail[q];
        }
        if(s[q+1] == s[i]){
            fail[i] = q + 1;
        } else {
            fail[i] = -1;
        }
    }
    for(int i = 0; i < s.length(); i++){
        cout << fail[i] << " ";
    }
    cout << endl;
}

int KMP(string b, string a){
    getFail(b);
    for(int i = 0, j = 0; i + j - b.length() <= a.length(); i++, j++){
        while(j != -1 && a[i] != b[j]) j = fail[j];
        if(j == b.length() - 1) ans[ind++] = i - j;
    }
    return -1;
}

int main(){
    cin >> x >> y;
    KMP(x, y);
    for(int i = 0; i < ind; i++) cout << ans[i] << " \n"[i == ind - 1];
}
