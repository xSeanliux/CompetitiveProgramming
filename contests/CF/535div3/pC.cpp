#include <iostream>
#include <string.h>
using namespace std;

int N;
string s;

string genString(int n, char a, char b, char c){
    string res = "";
    for(int i = 0; i < n; i++){
        if(i % 3 == 0) res += a;
        else if(i % 3 == 1) res += b;
        else res += c;
    }
    return res;
}

int getDist(string R, string b){
    int res = 0;
    for(int i = 0; i < R.length(); i++){
        res += (R[i] != b[i]);
    }
    return res;
}

int main(){
    cin >> N >> s;
    int minDist = N + 1;
    string Rrg = "";
    //RBG
    if(getDist(genString(N, 'R', 'B', 'G'), s) < minDist){
        minDist = getDist(genString(N, 'R', 'B', 'G'), s);
        Rrg = genString(N, 'R', 'B', 'G');
    }
    //RGB
    if(getDist(genString(N, 'R', 'G', 'B'), s) < minDist){
        minDist = getDist(genString(N, 'R', 'G', 'B'), s);
        Rrg = genString(N, 'R', 'G', 'B');
    }
    //BRG
    if(getDist(genString(N, 'B', 'R', 'G'), s) < minDist){
        minDist = getDist(genString(N, 'B', 'R', 'G'), s);
        Rrg = genString(N, 'B', 'R', 'G');
    }
    //BGR
    if(getDist(genString(N, 'B', 'G', 'R'), s) < minDist){
        minDist = getDist(genString(N, 'B', 'G', 'R'), s);
        Rrg = genString(N, 'B', 'G', 'R');
    }
    //GRB
    if(getDist(genString(N, 'G', 'R', 'B'), s) < minDist){
        minDist = getDist(genString(N, 'G', 'R', 'B'), s);
        Rrg = genString(N, 'G', 'R', 'B');
    }
    //GBR
    if(getDist(genString(N, 'G', 'B', 'R'), s) < minDist){
        minDist = getDist(genString(N, 'G', 'B', 'R'), s);
        Rrg = genString(N, 'G', 'B', 'R');
    }
    cout << minDist << endl;
    cout << Rrg << endl;
}
