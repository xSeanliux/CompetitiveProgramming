#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string s = "";
int q, N, ans;
vector<int> tScore, quepos;
char alp[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', 'x', '/'};


bool isn(char c){
    return c <= '9' && c >= '0';
}

bool isValid(string s){
    if(s.length() == 2){
        if(s[1] == '-'){
            return s[0] == 'x';
        }
        if(s[1] == '/'){
            return isn(s[0]);
        }
        return (s[0] + s[1] - '0' * 2 < 10);
    }
    if(s.length() == 3){
        if(s == "xxx") return true; //1
        if(s[0] == 'x'){
            if(s[1] == 'x') return isn(s[2]); //2
            if(isn(s[1])){
                if(isn(s[2])){
                    return (s[2] + s[1] - '0' * 2 < 10); //4
                }
                return s[2] == '/'; //3
            }
            return false;
        } else if(isn(s[0])){
            if(s[1] == '/'){
                if(s[2] == 'x') return true; //5
                return isn(s[2]); //6
            } else {
                return (s[0] + s[1] - '0' * 2 < 10) && s[2] == '-'; //7
            }
            return false;
        }
        return false;
    } else {
        return false;
    }
}

vector<int> getScore(string s){
    vector<string> parts;
    vector<int> r;
    for(int i = 0; i < s.length() - 2; i += 2){
        parts.push_back(s.substr(i, 2));
    }
    parts[N - 1] = s.substr(s.length() - 3, 3);
    for(string s : parts) if(!isValid(s)) return r;
    //cout << parts.size() << endl;
    for(int i = 0; i < N - 1; i++){
        int p = 0, cd;
        if(parts[i][1] == '/'){
            p = 10;
            cd = 1;
        } else if(parts[i][0] == 'x'){
            p = 10;
            cd = 2;
        } else {
            p = parts[i][0] + parts[i][1] - 2 * '0';
            cd = 0;
        }
        for(int j = 2 * (i + 1); j < 2 * N + 1 && cd; j++){
            if(s[j] == 'x'){
                p += 10;
                cd--;
            } else if(s[j] == '/'){
                p = p - (s[j - 1] - '0') + 10;
                cd--;
            } else if(isn(s[j])){
                p += s[j] - '0';
                cd--;
            }
        }
        r.push_back(p);
    }
    //now for the last part
    int p = 0;
    //cout << "LAST: " << parts[N - 1] << endl;
    for(int j = 2; j >= 0; j--){
        if(parts[N - 1][j] == 'x'){
            p += 10;
        } else if(parts[N - 1][j] == '/'){
            p += 10;
            j--;
        } else if(isn(parts[N - 1][j])){
            p += parts[N - 1][j] - '0';
        }
    }
    r.push_back(p);
    for(int i = 1; i <= N; i++){
        r[i] += r[i - 1];
    }

    return r;
}

void dfs(int pos = 0){
    if(pos == quepos.size()){
        cout << "Looking at " << s << endl;
        vector<int> r = getScore(s);
        if(r.size() == 0) return;
        for(int i = 0; i < N; i++) if(tScore[i] != -1 && r[i] != tScore[i]) return;
        ans++;
    }
    for(int i = 0; i < 13; i++){
        s[quepos[pos]] = alp[i];
        dfs(pos + 1);
    }
}

int main(){
    cin >> q;
    while(q--){
        ans = 0;
        cin >> N >> s;
        tScore.resize(N);
        for(int i = 0; i < N; i++) cin >> tScore[i];
        for(int i = 0; i < 2 * N + 1; i++){
            if(s[i] == '?') quepos.push_back(i);
        }
        dfs();
        cout << ans << endl;
    }
}
