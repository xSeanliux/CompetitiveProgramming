#include <iostream>
#include <set>
#include <string.h>
using namespace std;

int N, k, b; // y = kx + b
set<string> st;

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}

int sgn(int x){
    return (x >= 0 ? (x == 0) ? 0 : 1 : -1);
}

string tofrac(int a, int b){
    if(!a) return "0";
    char sign = (sgn(a) == sgn(b)) ? '+' : '-';
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    int g = gcd(a, b);
    a /= g;
    b /= g;
    string s = "";
    s += sign;
    s += to_string(a) + '/' + to_string(b);
    return s;
}


int main(){
    cin >> N;
    while(N--){
        cin >> k >> b;
        if(!k) continue;
        st.insert(tofrac(b, k));
    }
    cout << st.size() << endl;
}
