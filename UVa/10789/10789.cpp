#include <iostream>
#include <string.h>
using namespace std;

bool isPrime[3000];
int freqs[1000], prints, c;
string s;


void getPrime(){
    for(int i = 0; i < 2005; i++)
        isPrime[i] = i & 1;
    isPrime[2] = true;
    isPrime[1] = false;
    for(int i = 3 ; i < 2005; i+=2){
        if(isPrime[i]){
            for(int j = i * i; j < 2005; j += i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    getPrime();
    cin >> c;
    for(int ka = 1; ka <= c; ka++){
        cin >> s;
        prints = 0;
        for(int i = 0 ; i < 1000; i++){
            freqs[i] = 0;
        }
        int l = s.length();
        for(int i = 0 ; i < l; i++){
            freqs[s[i]]++;
            //cout << s[i] << "++, freq = " <<freqs[s[i]] <<  endl;
        }
        cout << "Case " << ka << ": ";
        for(int i = 0 ; i < 1000; i++){
            if(isPrime[freqs[i]]){
                cout << (char)(i);
                prints++;
            }
        }
        if(!prints)
            cout << "empty";
        cout << endl;


    }
}
