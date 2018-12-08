#include <iostream>
#include <string.h>
using namespace std;

int c, strs, len;
int best[1000][4]; //0 A, 1C 2 G 3T
string strings[1000];
string cS;

int getError(string str){
    int res = 0;
    for(int i = 0; i < strs; i++){
        string s = strings[i];
        for(int j = 0; j < len; j++){
            if(str[j] != s[j]) res++;
        }
    }
    return res;
}

int main(){
    cin >> c;
    for(int a = 0; a < c; a++){
        cin >> strs >> len;
        for(int i = 0; i < len; i++){
            best[i][0] = best[i][1] = best[i][2] = best[i][3] = 0;
        }
        for(int i = 0; i < strs; i++){
            cin >> cS;
            strings[i] = cS;
            for(int j = 0; j < len; j++){
                if(cS[j] == 'A'){
                    best[j][0]++;
                } else if(cS[j] == 'C'){
                    best[j][1]++;
                } else if(cS[j] == 'G'){
                    //cout << "G++" << endl;
                    best[j][2]++;
                } else {
                    best[j][3]++;
                }
            }
        }
        string ans = "";
        for(int i = 0; i < len; i++){
            int m, mI;
            m = mI = 0;
            for(int j = 0; j < 4; j++){
                if(best[i][j] > m){
                    m = best[i][j];
                    mI = j;
                }
            }
            if(mI == 0){
                ans += 'A';
            } else if(mI == 1){
                ans += 'C';
            } else if(mI == 2){
                ans += 'G';
            } else if(mI == 3){
                ans += 'T';
            }
        }
        cout << ans << endl << getError(ans) << endl;

    }
}
