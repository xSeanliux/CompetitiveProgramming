#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int maxN = 326, W = 26;
int N, T, nxt[W], prv[W], cnt[W], has[W];
bool used[maxN];


void dfs(int u, string &ans) {
    if(u == -1 || used[u]) return;
    used[u] = 1;  
    for(int i = 0; i < cnt[u]; i++) ans += (char)(u + 'A');
    dfs(nxt[u], ans);
}

bool isValid(string s) {
    fill(has, has + W, 0);
    has[s[0] - 'A'] = 1;
    for(int i = 1; i < s.length(); i++) if(s[i] != s[i - 1]) {
        if(has[s[i] - 'A']) return false;
        has[s[i] - 'A'] = true;
    }
    return true;
}

inline void solve(int t) {
    cin >> N;
    vector<string> strings = vector<string>(N);
    fill(used, used + maxN, 0);
    fill(cnt, cnt + W, 0);
    fill(prv, prv + W, -1);
    fill(nxt, nxt + W, -1);
    int lsum = 0;
    for(int i = 0; i < N; i++) {
        cin >> strings[i];
        lsum += strings[i].length();
        for(char c : strings[i]) cnt[c - 'A']++;
        for(int j = 0; j < strings[i].size() - 1; j++) {
            if(strings[i][j] != strings[i][j + 1]) {
                char a = strings[i][j], b = strings[i][j + 1];
                prv[b - 'A'] = a - 'A';
                nxt[a - 'A'] = b - 'A';
            }
        }
    }
    string ans = "";
    cout << "Case #" << t << ": ";
    for(int i = 0; i < W; i++) if(prv[i] == -1 && cnt[i]) dfs(i, ans);
    for(string s : strings) if(!isValid(s)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if(ans.length() != lsum) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    fill(used, used + maxN, 0);
    for(int pos = 0; pos < ans.length();) {
        bool f = false;
        for(int i = 0; i < N; i++){ 
            if(f) continue;
            //cout << "looking at " << ans.substr(pos, strings[i].length()) << " vs " << strings[i] << endl;
            //cout << (ans.substr(pos, strings[i].length()) == strings[i]) << " " << used[i] << endl;
            if(!used[i] && ans.substr(pos, strings[i].length()) == strings[i]) {
                pos += strings[i].length();
                used[i] = true;
                f = true;
                //cout << "setting used " << i << " to true" << endl;
                //cout << "found " << i << endl;
                //cout << "pos now " << pos << endl;
            }         
        }
        if(!f) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> T;
    for(int i = 1; i <= T; i++) solve(i);
}

