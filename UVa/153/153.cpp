#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string s;

long long int gcd(long long int a, long long int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    while(cin >> s){
        if(s == "#") return 0;
        int freqs[26];
        for(int i = 0; i < 26; i++) freqs[i] = 0;
        for(char c : s) freqs[c - 'a']++;
        long long ct = 0;
        for(int i = 0; i < s.length(); i++){
            //cout << "Checking char = " << s[i] << endl;
            //calculate this term
            for(int j = 0; j < s[i] - 'a'; j++){
                //cout << "freqs[" << (char)(j + 'a') << "] = " << freqs[j] << endl;
                if(freqs[j]){ //switch with j
                    //cout << "Switch with char " << (char)(j + 'a') << endl;
                    long long int toFact[s.length() - i];
                    for(int k = 0; k <= s.length() - i - 1; k++) toFact[k] = k;
                    //cout << "_ct = " << s.length() - i - 1 << "!" << endl;
                    freqs[j]--;
                    for(int k = 0; k < 26; k++){
                        if(freqs[k]){
                            //_ct /= facts[freqs[k]];
                            for(int l = 2; l <= freqs[k]; l++){
                                int tmp = l;
                                for(int m = 2; m <= s.length() - i - 1 && tmp > 1; m++){
                                    long long int g = gcd(tmp, toFact[m]);
                                    tmp /= g;
                                    toFact[m] /= g;
                                }
                            }
                            //cout << "_ct /= " << freqs[k] << "! (" << (char)(k + 'a') << ")" << endl;
                        }
                    }
                    long long int _ct = 1;
                    for(int k = 2; k <= s.length() - i - 1; k++) _ct *= toFact[k];
                    ct += _ct;
                    //cout << "_ct = " << _ct << endl;
                    freqs[j]++;
                }
                //cout << "freqs[a] = " << freqs[0] << endl;
            }
            //
            freqs[s[i] - 'a']--;
        }
        printf("%10ld\n", ct + 1);
    }
}
