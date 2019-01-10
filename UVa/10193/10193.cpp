#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

string s1, s2;
long long int C, val1, val2;
int main(){
    cin >> C;
    for(int c = 1; c <= C; c++){
        cin >> s1 >> s2;
        val1 = val2 = 0;
        int l1 = s1.length();
        for(int i = 0 ; i < l1; i++){
            val1 += pow(2, l1-i-1) * (s1[i] == '1');
        }

        int l2 = s2.length();
        for(int i = 0 ; i < l2; i++){
            val2 += pow(2, l2-i-1) * (s2[i] == '1');
        }
        if(gcd(val1, val2) > 1){
            printf("Pair #%d: All you need is love!\n", c);
        } else {
            printf("Pair #%d: Love is not all you need!\n", c);
        }
    }
}
