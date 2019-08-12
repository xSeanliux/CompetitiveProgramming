#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int T, yaofreq[14];
//由一萬、九萬、一餅、九餅、一索、九索、四風牌(東風、南風、西
//風、北風)、三元牌(白、發、中)
string s[15];
set<string> mp;

int main(){
    cin >> T;
    while(T--){
        mp.clear();
        int cnt = 0, _cnt = 0;
        for(int i = 0; i < 13; i++) yaofreq[i] = 0;
        for(int i = 0; i < 14; i++){
            cin >> s[i];
            if(!mp.count(s[i])){
                mp.insert(s[i]);
                _cnt++;
                //cout << "NEW: " << s[i] << endl;
            }
            if(s[i] == "1m"){
                yaofreq[0]++;
                cnt++;
            } else if(s[i] == "9m"){
                yaofreq[1]++;
                cnt++;
            } else if(s[i] == "1p"){
                yaofreq[2]++;
                cnt++;
            } else if(s[i] == "9p"){
                yaofreq[3]++;
                cnt++;
            } else if(s[i] == "1s"){
                yaofreq[4]++;
                cnt++;
            } else if(s[i] == "9s"){
                yaofreq[5]++;
                cnt++;
            } else if(s[i][1] == 'z'){
                yaofreq[s[i][0] - '0' + 5]++;
                cnt++;
            }
        }
        bool isA = true, isB = true;
        if(cnt == 14){
            for(int i = 0; i < 13; i++){
                if(!yaofreq[i]){
                    isA = false;
                }
            }
        } else {
            isA = false;
        }
        //cout << "_cnt = " << _cnt << endl;
        if(_cnt != 7){
            isB = false;
        }
        if(isA){
            cout << "kokushi musou(Thirteen orphans)" << endl;
        } else if(isB){
            cout << "chiitoitsu(Seven pairs)" << endl;
        } else {
            cout << "none" << endl;
        }
    }
}
