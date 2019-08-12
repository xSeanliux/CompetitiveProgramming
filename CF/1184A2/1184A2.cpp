#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;


const int maxN = 2e5;

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}

int N;
bool vals[maxN + 10];
string s;
map<int, int> gcdcnt;
int main(){
    cin >> N >> s;
    bool isAllZero = true;
    for(int i = 1; i <= N; i++){
        gcdcnt[gcd(i, N)]++;
    }
    for(int i = 0; i < N; i++){
        vals[i] = s[i] - '0';
        if(vals[i]) isAllZero = false;
    }
    vector<int> v;
    int ans = 0;
    for(int f = 1; f < N; f++){
        if(!(N % f)){
            v.clear();
            v.resize(f);
            fill(v.begin(), v.end(), 0);
            for(int i = 0; i < N; i++){
                v[i % f] ^= vals[i];
            }
            bool isgood = true;
            for(bool u : v){
                if(u){
                    isgood = false;
                    break;
                }
            }
            if(isgood){
                ans += gcdcnt[f];
            }
        }
    }

    cout << ans + isAllZero << endl;
}
