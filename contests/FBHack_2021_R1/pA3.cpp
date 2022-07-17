#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int M = 1e9 + 7;

inline int add(int a, int b){
    return (a + b >= M ? a + b - M : a + b);
}

int fd, ld, f, l, suf, pre, ans, len, pairnum, sumf, cntf;

inline void dupe(){
    cout << "duping, " << suf << ", " << pre << endl;
    cout << "f = " <<f << ", l = " << l << endl;
    suf = add(2 * suf % M, len * ans % M);
    pre = add(2 * pre % M, len * ans % M);
    ans = add(ans * 2 % M, suf * pre % M);
    pairnum = 2 * pairnum % M;
    sumf = add(2 * sumf % M, len * cntf % M);
    cntf = cntf * 2 % M;
    if(f + l == 3){
        suf = add(suf, (len - ld + 1 + M) % M);
        pre = add(pre, (len - fd + 1 + M) % M);
        ans = add(ans, ((len - ld + 1 + M) % M) * ((len - fd + 1 + M) % M) % M);
        pairnum = add(pairnum, 1);
        cntf = add(cntf, 1);
    }
    len = len * 2 % M;
}

inline void add(char c){
    cout << "adding " << c << endl;
    pre = add(pre, ans);
    ans = add(ans, sumf);
    if(c == 'F'){
        ld = add(ld, 1);
    } else if(c == 'O'){
        if(!f){
            l = f = 1;
            fd = add(len, 1);
            ld = 1;
        }
        if(l == 2){
            suf = add(suf, (len - ld + 1 + M) % M);
            pre = add(pre, 1);
            pairnum = add(pairnum, 1);
            ans = add(ans, (len - ld + 1 + M) % M);
            sumf = add(sumf, (len - ld + 1 + M) % M);
            cntf = add(cntf, 1);
        }
        l = 1;
        ld = 1;
    } else {
        if(!f){
            l = f = 2;
            fd = add(len, 1);
            ld = 1;
        }
        if(l == 1){
            suf = add(suf, (len - ld + 1 + M) % M);
            pre = add(pre, 1);
            pairnum = add(pairnum, 1);
            ans = add(ans, (len - ld + 1 + M) % M);
            sumf = add(sumf, (len - ld + 1 + M) % M);
            cntf = add(cntf, 1);
        }
        l = 2;
        ld = 1;
    }
    len = add(len, 1);
}

inline void printState(){
    cout << "f = " << f << ", l = " << l << ", fd = " << fd << ", ld = " << ld << ", pre = " << pre << ", suf = " << suf << ", ans = " << ans << ", len = " << len << ", pn = " << pairnum << endl;
}

inline void solve(int tc){
    int N;
    string s;
    cin >> N >> s;
    fd = ld = suf = pre = ans = len = f = l = pairnum = sumf = cntf = 0;
    //lo, lx, fo, fx: first/last 'O'/'X' (distance)
    //suf/pre: sum of suffix/prefix substrings
    //ans: ans
    //f, l: type of first/last character (1 for O, 2 for X, 3 for F, 0 for none)
    //len: length of string
    printState();
    for(char c : s){
        if(c == '.') dupe();
        else add(c);
        printState();
    }
    cout << "Case #" << tc << ": " <<ans << endl;
}

signed main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
}


