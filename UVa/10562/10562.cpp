#include <iostream>
#include <string.h>
using namespace std;

int T, l, mL, maxH;
char mp[300][300];
string s;

void dfs(int i, int j){
    if(i >= maxH) return;
    printf("%c(", mp[i][j]);
    if(mp[i+1][j] == '|'){
        int lE = j, rE = j;
        while(mp[i+2][lE] == '-') lE--;
        while(mp[i+2][rE] == '-') rE++;
        lE++; rE--;
        for(int k = lE; k <= rE; k++){
            if(mp[i+3][k] != ' ' && mp[i+3][k] != '#') dfs(i + 3, k);
        }
    }
    printf(")");
}

int main(){
    cin >> T;
    getline(cin, s);
    while(T--){
        mL = 0;
        maxH = 0;
        int starti = -1, startj = -1;
        for(int i = 0; i < 300; i++)
            for(int j = 0; j < 300; j++)
                mp[i][j] = ' ';
        for(;;maxH++){
            getline(cin, s);
            if(s == "#") break;
            mL = max(mL, (int)s.length());
            for(int j = 0; j < s.length(); j++){
                mp[maxH][j] = s[j];
                if(starti == -1 && s[j] != ' '){
                    starti = maxH;
                    startj = j;
                }
            }
        }
        printf("(");
        if(starti > -1)
            dfs(starti, startj);
        printf(")\n");
    }
}
