#include <iostream>
#include <string.h>
#include <map>
using namespace std;

string ms = "abdeopq!cfhijklmnrstuvwxyz!", s;
map <char, char> m;
int T, N, K; //length is N, with K holes

bool hasHole(char c){
    if(c == 'a' || c == 'b' || c == 'd' || c == 'e' || c == 'o' || c == 'p' || c == 'q')
        return true;
    return false;
}
//length 5 and 2 holes

int getHoles(string s){
    int l = s.length(), ans = 0;
    for(int i = 0 ; i < l; i++){
        ans += hasHole(s[i]);
    }
    return ans;
}

string genString(int len, int holes){
    if(len < holes) return "-";
    else{
        string s = "";
        while(holes){
            s += 'a';
            len--;
            holes--;
        }
        while(len){
            s += 'c';
            len--;
        }
        return s;
    }
}

int main(){
    int l = ms.length();
    for(int i = 0 ; i < l; i++){
        m.insert(pair<char, char>(ms[i], ms[i+1]));
        m['q'] = 'r';
    }
    cin >> T;
    while(T--){
        cin >> N >> K >> s;
        bool isGood = false;
        int currentNoHole = 0;
        for(int i = N-1; i >= 0; i--){
            currentNoHole += !hasHole(s[i]);
            //cout << "i = " << i << ", noHoles: " << currentNoHole << endl;
            if(s[i] == 'q' && currentNoHole > 0){
                //cout << "generating: len" << N-i-1 << " , " << N - i - currentNoHole << " holes" << endl;
                string newS = genString(N - i - 1, N - i - currentNoHole);
                //cout << "newS = " << newS << endl;
                cout << s.substr(0, i) + 'r' + newS << endl;
                isGood = true;
                break;
            } else if(s[i] != 'q' && m[s[i]] != '!'){
                s[i] = m[s[i]];
                if(s[i] == 'y'){
                    string newS = genString(N - i - 1, N - i - currentNoHole);
                    cout << s.substr(0, i+1) + newS << endl;
                } else {
                    cout << s << endl;
                }
                
                isGood = true;
                break;
            }
        }
        if(!isGood)
            cout << -1 << endl;
    }
}

/*
 int main(){
 for(int i = 0; i < 25; i++){
 m.insert(pair<char, char>(ms[i], ms[i+1]));
 }
 for(int i = 0; i < 25; i++){
 for(int j = 0; j < 25; j++){
 for(int k = 0; k < 25; k++){
 for(int l = 0; l < 25; l++){
 for(int mt = 0; mt < 25; mt++){
 string s = "";
 s += ms[i];
 s += ms[j];
 s += ms[k];
 s += ms[l];
 s += ms[mt];
 if(getHoles(s) == 2)
 cout << s << endl;
 }
 }
 }
 }
 }
 }
 */


