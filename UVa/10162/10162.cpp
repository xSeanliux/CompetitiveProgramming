#include <iostream>
#include <string.h>
using namespace std;

int fastexp(int b, int e, int M){
    if(e == 1) return b % M;
    int res = fastexp(b, e/2, M);
    res = res * res % M;
    if(e % 2) res = res * b % M;
    return res;
}

int ans[100];
string s;

int main(){
    ans[0] = 0;
    int res = 0;
    for(int i = 1; i < 100; i++){
        res += fastexp(i, i, 10);
        res %= 10;
        ans[i] = res;
        //printf("%d: %d， res = %d\n", i, res, fastexp(i, i, 10));
    }
    while(cin >> s){
        if(s == "0") return 0;
        if(s.length() <= 2) cout << ans[stoi(s)] << endl;
        else cout << ans[stoi(s.substr(s.length()-2, 2))] << endl;
    }
}
