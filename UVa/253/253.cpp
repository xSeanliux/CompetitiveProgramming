#include <iostream>
#include <string.h>
using namespace std;

string cubes, c1, c2, rot;
int l = 6, now[4];
bool isSame = false;
string rotx(string s){
    string ans = "";
    ans += s[1];
    ans += s[5];
    ans += s[2];
    ans += s[3];
    ans += s[0];
    ans += s[4];
    return ans;
}

string roty(string s){
    string ans = "";
    ans += s[0];
    ans += s[2];
    ans += s[4];
    ans += s[1];
    ans += s[3];
    ans += s[5];
    return ans;
}

string rotz(string s){
    string ans = "";
    ans += s[2];
    ans += s[1];
    ans += s[5];
    ans += s[0];
    ans += s[4];
    ans += s[3];
    return ans;
}

void dfs(int ite){
    //cout <<"hey " << endl;
    if(isSame) return;
    if(ite == 4){
        string res = c1;
        for(int i = 0 ; i < ite; i++){
            if(now[i] == 1){
                res = rotx(res);
            } else if(now[i] == 2){
                res = roty(res);
            } else if(now[i] == 3){
                res = rotz(res);
            }
        }
        //cout << res << endl;
        if(res == c2){
            isSame = true;
        }
    } else {
        for(int i = 0 ; i < 4; i++){
            now[ite] = i;
            dfs(ite + 1);
        }
    }
}


int main(){
    while(cin >> cubes){
        isSame = false;
        c1 = cubes.substr(0, 6);
        c2 = cubes.substr(6);
        //cout << c1 << ", " << c2 << endl;
        dfs(0);
        if(isSame){
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }
}
