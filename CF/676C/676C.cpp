#include <iostream>
#include <string.h>
#include <iostream>
using namespace std;

int main(){
    string s;
    int N, K;
    cin >> N >> K >> s;
    int aCnt = 0, bCnt = 0, l = 0, r = 0;
    int ans = 0;
    while(r < N){
        while(aCnt <= K || bCnt <= K){
            (s[r] == 'a' ? aCnt : bCnt)++;
            //printf("aCnt, bCnt = %d, %d\n", aCnt, bCnt);
            r++;
            if(r == N) break;
        }
        //cout << "(l, r) = (" << l << ", " << r << ")" << endl;
        if((aCnt <= K || bCnt <= K) && r == N){
            ans = max(ans, r - l);
        } else {
            ans = max(ans, r - l - 1);
        }
        while(aCnt > K && bCnt > K){
            (s[l] == 'a' ? aCnt : bCnt)--;
            l++;
        }
        //cout << "(l, r) = (" << l << ", " << r << ")" << endl;
        ans = max(ans, r - l);
    }
    cout << ans << endl;
}
