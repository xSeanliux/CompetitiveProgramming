#include <iostream>
#include <string.h>
#define int unsigned long long int
using namespace std;

int N, k;
string tgt;

string toStr(int x){
    string res = "";
    while(x){
        res = (char)(x % 2 + '0') + res;
        x /= 2;
    }
    return res;
}

int f(string str){
    string cmp = tgt.substr(0, str.length());
    int res;
    if(cmp == str){ //is prefix
        res = (1ULL << (tgt.length() - str.length())) - 1; //all lengths smaller
        for(int i = str.length(); i < tgt.length(); i++){
            if(tgt[i] == '1'){
                res += (1ULL << (tgt.length() - i - 1));
            }
        }
        res++; //choose = tgt itself
    } else if(cmp > str){ //is smaller!
        res = (1ULL << (tgt.length() - str.length() + 1)) - 1;
    } else { //is larger
        res = (1ULL << (tgt.length() - str.length())) - 1;
    }
    if(str[str.length() - 1] == '0'){
        str[str.length() - 1] = '1';
        res += f(str);
    }
    return res;
}

int getPath(int x){
    if(x > N) return 0;
    else return f(toStr(x));
}

signed main(){
    cin >> N >> k;
    //cout << "N = " << N << endl;
    tgt = toStr(N);
    int l = 1, r = (N + 10) / 2, m, a, b;
    while(l + 1 < r){
        m = (l + r) / 2;
        //cout << "M = " << m << endl;
        //cout << "2 * m = " << 2 * m << endl;
        //cout << "getPath(" << 2 * m << ") = " << f(toStr(2 * m)) << endl;
        if(getPath(2 * m) >= k){
            l = m;
        } else r = m;
    }
    a = 2 * l;
    l = 0, r = (N + 10) / 2;
    while(l + 1 < r){
        m = (l + r) / 2;
        if(getPath(2 * m  + 1) >= k){
            l = m;
        } else r = m;
    }
    b = 2 * l + 1;
    //cout << "GetPath(" << a << ") = " << getPath(a) << endl;
    if(getPath(a) < k) cout << b << endl;
    else cout << max(a, b) << endl;
}
