#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;

int N, ans, a[(int)2e5 + 10], b[(int)2e5 + 10], bZero;
map<string, int> fracs;

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}

string getFrac(int a, int b){ //get a/b
    if(!b){
        bZero += (a == 0);
        //cout << "FOR " << a << "/" << b << ", bzero = " << bZero << endl;
        return "INF";
    }
    if(!a) return "0";
    bool isNeg = ((long long int)a * (long long int)b < 0);
    a = abs(a); b = abs(b);
    int g = gcd(a, b);
    a /= g; b /= g;
    string res = "";
    if(isNeg) res += '-';
    res += to_string(a) + '/' + to_string(b);
    return res;
}

int main(){
    //cout << getFrac(-2, 4) << endl;
    cin >> N;
    bZero = 0;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    for(int i = 0; i < N; i++){
        string currentFrac = getFrac(b[i], a[i]);
        if(fracs.count(currentFrac)) fracs[currentFrac]++;
        else fracs.insert({currentFrac, 1});
    }
    int ans = 0;
    fracs["INF"] = -1;
    for(auto i : fracs) ans = max(ans, i.second);
    //printf("ans: %d, bzero: %d\n", ans, bZero);
    ans += bZero;
    cout << ans << endl;
}
