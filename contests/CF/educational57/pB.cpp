#include <iostream>
#include <string.h>
#define MOD 998244353
using namespace std;

int l, ans = 0;
string s;

int main(){
    cin >> l >> s;
    ans = 1; //empty string
    char c = s[0];
    long long int left = 0, right = 0;
    while(s[left] == s[0]) left++;
    while(s[l - right - 1] == s[l-1]) right++;
    if(s[0] == s[l-1]){
        printf("%lld\n", (left + 1)*(right + 1) % MOD);
    } else {
        printf("%lld\n", (left+1) + (right + 1) - 1);
    }
}
