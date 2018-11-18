#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int c, N;
int main(){
    scanf("%d\n", &c);
    for(int ia = 0; ia < c; ia++){
        cin >> N;
        int b1 = 0;
        int t = N;
        while(t > 0){
            int l = t%2;
            b1 += l;
            t -= l;
            t /= 2;
        }
        int inHex = 0;
        string st = to_string(N);
        reverse(st.begin(), st.end());
        int l = st.length();
        for(int i = 0; i < l; i++){
            inHex += (int)(st[i] - '0') * pow(16, i);
        }
        int t2 = inHex, b2 = 0;
        while(t2 > 0){
            int l = t2%2;
            b2 += l;
            t2 -= l;
            t2 /= 2;
        }
        printf("%d %d\n", b1, b2);

    }
}
