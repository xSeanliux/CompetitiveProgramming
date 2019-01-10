#include <iostream>
#include <string.h>
using namespace std;

string a, b;

class Obj{
public:
    int dist;
    char c;
    int dels;
    bool operator()(const Obj a, const Obj b){
        return a.dist < b.dist;
    }
} dp[25][25];

string format(int K){
    string s;
    s += ((K/10) + '0');
    s += ((K % 10) + '0');
    //cout << "format(" << K << ") = " << s << endl;
    return s;
}

int main(){
    while(getline(cin, a)){
        if(a == "#") return 0;
        if(a == ""){
            cout << "E" << endl;
            continue;
        }
        int l = a.length();
        for(int i = 0; i < l; i++){
            if(a[i] == ' '){
                //cout << i << endl;
                if(i < l - 1){
                    //cout << "substr: " << (i+1) << endl;
                    b = a.substr(i+1, l);
                } else b = "";
                a = a.substr(0, i);
                //cout << "H"<<endl;
                //cout << a << "/" << b << endl;
                break;
            }
        }
        int lA = a.length(), lB = b.length();
        for(int i = 0; i <= lA; i++){
            for(int j = 0; j <= lB; j++){
                dp[i][j].dist = 0;
                dp[i][j].dels = 0;
            }
        }
        a = '+' + a; //start at 1
        b = '-' + b; //start at 1
        for(int i = 1; i <= lA; i++){
            dp[i][0].dist = i;
            dp[i][0].c = 'D';
            dp[i][0].dels = i;
        }
        for(int i = 1; i <= lB; i++){
            dp[0][i].dist = i;
            dp[0][i].c = 'I';
            dp[0][i].dels = -i;
        }
        /*
        cout << "  ";
        for(int i = 1; i <= lB; i++){
            cout << b[i] << "   ";
        }
        cout << endl;
        */
        for(int i = 1; i <= lA; i++){
            //cout << a[i] << " ";
            for(int j = 1; j <= lB; j++){
                if(a[i] == b[j]){
                    dp[i][j].dist = dp[i-1][j-1].dist;
                    dp[i][j].c = 'N';
                    dp[i][j].dels = dp[i-1][j-1].dels;
                } else {
                    dp[i][j].dist = dp[i-1][j].dist + 1;
                    dp[i][j].c = 'D';
                    dp[i][j].dels = dp[i-1][j].dels + 1;
                    if(dp[i][j-1].dist < dp[i][j].dist){
                        dp[i][j].dist = dp[i][j-1].dist + 1;
                        dp[i][j].c = 'I';
                        dp[i][j].dels = dp[i][j-1].dels - 1;
                    }
                    if(dp[i-1][j-1].dist < dp[i][j].dist){
                        dp[i][j].dist = dp[i-1][j-1].dist + 1;
                        dp[i][j].c = 'C';
                        dp[i][j].dels = dp[i-1][j-1].dels;
                    }
                }
                //if(dp[i][j].dist < 10) cout << 0;
                //cout << dp[i][j].dist << dp[i][j].c << " ";
            }
           // cout << endl;
        }
        string ansStr = "", _s;
        int x = lB, y = lA;
        while(x >= 0 && y >= 0){
            //cout << "y = " << y << "correct: " << dp[y][x].dels + 1 << endl;
            if(dp[y][x].c == 'N'){
                y--;
                x--;
            } else if(dp[y][x].c == 'D'){
                _s = 'D';
                _s += a[y] + format(y - dp[y][x].dels + 1);
                ansStr = _s + ansStr;
                y--;
            } else if(dp[y][x].c == 'I'){
                _s = 'I';
                _s += b[x] + format(y - dp[y][x].dels);
                ansStr = _s + ansStr;
                x--;
            } else if(dp[y][x].c == 'C'){
                _s = 'C';
                _s += b[x] + format(y - dp[y][x].dels);
                ansStr = _s + ansStr;
                x--;
                y--;
            }
            //cout << "y = " << y << ", x = " << x << ", str = " << ansStr << endl;
            if(!x & !y) break;
        }
        ansStr += 'E';
        cout << ansStr << endl;
    }

}
