#include <iostream>
#include <set>
#include <string.h>
#include <map>
using namespace std;

string s;

int T;

int main(){
    cin >> T;
    while(T--){
        set<string> yao, all;
        map<string, int> _all;
        bool isMusou = true, isChii = true;
        for(int i = 0; i < 14; i++){
            cin >> s;
            if(s[0] == '1' || s[0] == '9' || s[1] == 'z'){
                if(!yao.count(s)) yao.insert(s);
            } else {
                isMusou = false;
            }
            all.insert(s);
            _all[s]++;
            if(_all[s] > 2) isChii = false;
        }
        if(isMusou && yao.size() == 13){
            cout <<"kokushi musou(Thirteen orphans)" << endl;
        } else if(isChii && all.size() == 7){
            cout << "chiitoitsu(Seven pairs)" << endl;
        } else {
            cout << "none" << endl;
        }
    }
}
