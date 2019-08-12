#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string s;

vector<int> getFail(string s){
    vector<int> fail;
    fail.resize(s.length());
    fail[0] = -1; //QQ
    for(int i = 1; i < s.length(); i++){
        int q = fail[i - 1];
        while(q >= 0 && s[q + 1] != s[i]){
            q = fail[q];
        }
        if(s[q + 1] == s[i]) q++;
        fail[i] = q;
    }
    return fail;
}

int getlen(string a, string b){ //gets longest k s.t. suf_k(a) = pre_k(b)
    string s = b + '$' + a;
    vector<int> fail = getFail(s);
    return fail[s.length() - 1] + 1;
}

int N;
string ans = "", cs;
int main(){
    ericxiao;
    cin >> N;
    int k;
    for(int i = 0; i < N; i++){
        cin >> cs;
        if(!i){
            ans += cs;
            continue;
        }
        k = getlen(ans.substr(max(0, (int)(ans.length() - cs.length()))), cs);
        //cout << "k = " << k << endl;
        for(int i = k; i < cs.length(); i++){
            ans += cs[i];
        }
    }
    cout << ans << endl;
}
