#include <iostream>
#include <string.h>
using namespace std;

string str;

int freqs[200], mF;

int main(){
    while(getline(cin, str)){
        mF = 0;
        memset(freqs ,0, sizeof freqs);
        int l = str.length();
        for(int i = 0 ; i < l; i++){
            if(('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')){
                //cout << "scanning " << str[i] << endl;
                freqs[str[i]]++;
                if(freqs[str[i]] >= mF){
                    //cout << "Hey" << endl;
                    mF = freqs[str[i]];
                }
            }
        }
        for(int i = 'A' ; i <= 'z'; i++){
            if(freqs[i] == mF){
                //cout << freqs[i] << endl;
                cout << (char)(i);
            }
        }
        cout << " " << mF << endl;
    }
}

