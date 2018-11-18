#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int c, ques, sz, so, tz, to, diff, ans;
string S, T;
bool canBeDone;

int main(){
    cin >> c;
    for(int ka = 1 ; ka <= c; ka++){
        cin >> S >> T;
        int l = S.length();
        canBeDone = true;
        ques = sz = so = tz = to = diff = 0;
        for(int i = 0; i < l; i++){
            if(S[i] == '?'){
                ques++;
            } else if(S[i] == '0'){
                sz++;
            } else if(S[i] == '1'){
                so++;
            }

            if(T[i] == '0'){
                tz++;
            } else if(T[i] == '1'){
                to++;
            }
        }
        int needOnes = to - so;
        int needZeroes = tz - sz;
        cout << "ques: " << ques << endl;
        cout << "Need " << needOnes << " 1s, and " << needZeroes << " 0s." << endl;
        if(needOnes < 0 || needZeroes < 0 || needOnes + needZeroes != ques)
            canBeDone = false;
        if(canBeDone){
            for(int i = 0 ; i < l; i++){
                if(S[i] == '?'){
                    if(T[i] == '0'){
                        if(needZeroes > 0){
                            needZeroes--;
                            S[i] = '0';
                        } else {
                            needOnes--;
                            S[i] = '1';
                        }
                    } else if(T[i] == '1'){
                        if(needOnes > 0){
                            needOnes--;
                            S[i] = '1';
                        } else {
                            needZeroes--;
                            S[i] = '0';
                        }
                    }

                }
            }
            cout << S << endl;
        }
        printf("Case %d: ", ka);
        for(int i = 0 ; i < l; i++){
            diff += !(S[i] == T[i]);
        }
        if(diff%2) canBeDone = false;
        if(canBeDone){
            cout << ques + diff/2 << endl;
        } else {
            cout << -1 << endl;
        }

    }
}
