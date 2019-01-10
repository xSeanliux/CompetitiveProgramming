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

string succ(string s){
    int N = s.length(), amo = 0;
    bool isGood = false;
    int currentNoHole = 0;
    for(int i = N-1; i >= 0; i--){
            currentNoHole += !hasHole(s[i]);
            //cout << "i = " << i << ", noHoles: " << currentNoHole << endl;
            if(s[i] == 'q' && currentNoHole > 0){
                //cout << "generating: len" << N-i-1 << " , " << N - i - currentNoHole << " holes" << endl;
                string newS = genString(N - i - 1, N - i - currentNoHole);
                //cout << "newS = " << newS << endl;
                return s.substr(0, i) + 'r' + newS;
                isGood = true;
                break;
            } else if(s[i] != 'q' && m[s[i]] != '!'){
                char ori = s[i];
                s[i] = m[s[i]];
                //cout << "hey" << endl;
                string newS;
                if(hasHole(ori)){
                    newS = genString(N - i - 1, max(0, N - i - currentNoHole - 1));
                } else {
                    newS = genString(N - i - 1, N - i - currentNoHole);
                }
                return s.substr(0, i+1) + newS;
                isGood = true;
                break;
            }
        }
    return "-1";

}

void f(){
    cout <<" this is the standard ans" << endl;
    string ms = "abcdefhijklmnopqrstuvwxyz", s;
    int amo = 0;
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++){
            for(int k = 0; k < 25; k++){
                for(int l = 0; l < 25; l++){
                    for(int mt = 0; mt < 25; mt++){
                        s = "";
                        s += ms[i];
                        s += ms[j];
                        s += ms[k];
                        s += ms[l];
                        s += ms[mt];
                        if(getHoles(s) == 2){
                            cout << "#" << ++amo <<": " <<s << endl;
                            //if(amo == 10000) return;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int l = ms.length();
    for(int i = 0 ; i < l; i++){
        m.insert(pair<char, char>(ms[i], ms[i+1]));
        m['q'] = 'r';
    }
    string s = "aaaaa";
    //cout<<succ("aazzz")<<endl;
    int am = 0;
    /*
    while(s != "-1"){
        cout << "#" << ++am << ": " << s << endl;
        s = succ(s);
        //if(am == 10000) return 0;
    }

    */

    f();





    cin >> T;
    while(T--){
        cin >> N >> K >> s;
        cout << succ(s) << endl;
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

