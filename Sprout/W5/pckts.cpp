#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long int s1, s2, s3, s4, s5, s6;
    while (cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6){
        if(s1 + s2 + s3 + s4 + s5 + s6 == 0) return 0;
        int ans = 0;
        ans += s6;
        ans += s5;
        s1 -= s5 * 11;
        ans += s4;
        s2 -= s4 * 5;
        ans += (s3 + 3) / 4;
        if (s3 % 4 == 1){
            s2 -= 5;
            s1 -= 7;
        }
        else if (s3 % 4 == 2){
            s2 -= 3;
            s1 -= 6;
        }
        else if (s3 % 4 == 3){
            s2 -= 1;
            s1 -= 5;
        }
        if (s2 > 0){
            ans += (s2 + 8) / 9;
            s2 -= 9 * ((s2 + 8) / 9);
        }
        if (s2 < 0)
            s1 += s2 * 4;
        if (s1 > 0)
            ans += (s1 + 35) / 36;

        cout << ans << endl;
    }
    return 0;
}
