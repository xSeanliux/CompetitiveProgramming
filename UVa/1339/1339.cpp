#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

string A, B;


int main(){
    while(cin >> A >> B){
        map <char, int> freqs;
        int otherFreq[26];
        bool canGo = true;
        int l = A.length();
        for(int i = 0 ; i < l; i++){
            if(!freqs.count(A[i]))
                freqs.insert(pair<char, int>(A[i], 1));
            else
                freqs[A[i]]++;
        }
        for(int i = 0 ; i < 26; i++){
            otherFreq[i]= 0;
        }
        for(int i = 0 ; i < l; i++){
            otherFreq[(B[i] - 'A')]++;
            //cout << "oF[" << B[i] - 'A' << "] = " << otherFreq[(B[i] - 'A')] << endl;
        }
        for(map<char, int>::iterator i = freqs.begin(); i != freqs.end(); i++){
            int F = i->second;
            for(int i = 0; i < 26; i++){
                if(otherFreq[i] == F){
                    otherFreq[i] = 0;
                    break;
                }
            }
        }
        for(int i = 0; i < 26; i++){
            if(otherFreq[i]){
                canGo = false;
            }
        }
        if(canGo){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
