#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

int q;
string s, t, p;

int main(){
    cin >> q;
    while(q--){
        cin >> s >> t >> p;
        int sPointer = 0, tPointer = 0;
        map<char, int> needMap, pMap;
        while(sPointer < s.length() && tPointer < t.length()){
            if(s[sPointer] == t[tPointer]){
                sPointer++;
            } else {
                needMap[t[tPointer]]++;
            }
            tPointer++;
        }
        while(tPointer < t.length()){
            needMap[t[tPointer++]]++;
        }
        if(sPointer < s.length()){
            cout << "NO" << endl;
            continue;
        }
        for(char c : p){
            if(needMap[c]){
                needMap[c]--;
            }
        }
        bool canDo = true;
        for(auto x : needMap){
            if(x.second != 0){
                cout << "NO" << endl;
                canDo = false;
            }
            if(!canDo){
                break;
            }
        }
        if(canDo){
            cout << "YES" << endl;
        }
    }
}
