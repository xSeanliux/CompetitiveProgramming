#include <iostream>
#include <string.h>
using namespace std;

string s;
long long int ans, fact[21], N, freq[26];



int main(){
    fact[0] = 1;
    for(int i = 1; i <= 20; i++){
        fact[i] = i * fact[i-1];
    }
    cin >> N;
    for(int c = 1; c <= N; c++){
        cin >> s;
        for(int i = 0 ; i < 26; i++){
            freq[i] = 0;
        }
        int l = s.length();
        for(int i = 0 ; i < l; i++){
            freq[s[i] - 'A']++;
        }
        ans = fact[l];
        for(int i = 0; i < 26; i++){
            ans /= fact[freq[i]];
        }
        printf("Data set %d: %lld\n", c, ans);
    }


}
