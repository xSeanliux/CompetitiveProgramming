#include <iostream>
#include <string.h>
using namespace std;

const int maxC = (1 << 21);

bool has[maxC + 10];
int dp[maxC + 10];

string s;

inline int lowbit(int x){
    return (x & -x);
}

inline bool hasBit(int i, int j){
    return ((i & (1LL << j)) > 0);
}

inline void printBits(int x){
    for(int i = 0; i < 20; i++){
        if(hasBit(x, i)) cout << i << " ";
    }
    cout << endl;
}

inline int bitCount(int x){
    int r = 0;
    while(x){
        r++;
        x -= lowbit(x);
    }
    return r;
}

int main(){
    cin >> s;
    int tw = 0, bc;
    fill(dp, dp + maxC, 0);
    fill(dp, dp + maxC, 0);
    has[0] = true;
    for(int i = 0; i < s.length(); i++){
        tw = 0, bc = 0;
        for(int j = i; j < s.length(); j++){
            if(hasBit(tw, s[j] - 'a')) break;
            tw |= (1LL << (s[j] - 'a'));
            bc++;
            dp[tw] = bc;
            has[tw] = true;
        }
    }
    int mask;
    for(int i = 1; i < maxC; i++){
        mask = i;
        while(mask > 0){
            dp[i] = max(dp[i], dp[i ^ lowbit(mask)]);
            mask ^= lowbit(mask);
        }
    }
    int ans = 0;
    for(int i = 0; i < maxC; i++){
        if(has[i]){
            //cout << "HAS " << i << endl;
            //printBits(i);
            ans = max(ans, bitCount(i) + dp[((maxC) - 1) ^ i]);
        }
    }
    cout << ans << endl;
}
