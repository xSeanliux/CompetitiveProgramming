#pragma GCC optimize("Ofast", "no-stack-protector", "no-math-errno", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2")
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6;
int assign[maxN], impdone[maxN], ans;
map<string, int> id;

inline void addId(string &s) {
   if(!id.count(s)) id[s] = id.size(); 
}

struct Imp {
    vector<int> cond;
    vector<string> _cond;
    string _tgt;
    int tgt;
    bool type; //1 for and, 0 for or
    Imp(): cond(vector<int>()), _cond(vector<string>()) {}
    Imp(string _tgt, bool type): cond(vector<int>()), _cond(vector<string>()), _tgt(_tgt), type(type) {}
    void process() {
        tgt = id[_tgt];
        for(auto s : _cond) cond.push_back(id[s]);
    }
    bool satisfy() {
        if(type) {
            for(auto x : cond) if(assign[x] != 1) return false;
            if(!assign[tgt]) ans++;
            assign[tgt] = 1;
            return true;
        } else {
            for(auto x : cond) if(assign[x] == 1){
                if(!assign[tgt]) ans++;
                assign[tgt] = 1;
                return true;
            }
            return false;
        }
    }
};

vector<Imp> imps;



signed main() {
    int N;
    string s;
    fill(assign, assign + maxN, 0);
    cin >> N; 
    getline(cin, s);
    while(N--) {
        getline(cin, s); 
        vector<string> tokens;
        string cur = "";
        for(char c : s) {
            if(c == ' ') {
                tokens.push_back(cur);
                cur = "";
            } else cur += c;
        }
        tokens.push_back(cur);
        if(tokens[0] == "if") {
            bool type = (tokens[2] == "and");
            Imp imp = Imp(tokens[tokens.size() - 1], type); 
            addId(tokens[tokens.size() - 1]);
            for(int i = 1; i < tokens.size() - 1; i += 2){
                imp._cond.push_back(tokens[i]);
                addId(tokens[i]);
            }
            imps.push_back(imp);
        } else {
            addId(tokens[0]);
            if(!assign[id[tokens[0]]]) ans++;
            assign[id[tokens[0]]] = 1;
        }
    }
    /*
    for(auto [a, b] : id) {
        cout << a << " -> " << b << endl;
    }
    */
    for(int i = 0; i < imps.size(); i++) imps[i].process();
    bool f = true;
    while(f) {
        f = false;
        for(int i = 0; i < imps.size(); i++) {
            //cout << " i= " << i << endl;
            if(!impdone[i] && imps[i].satisfy()) {
                //cout << "satisfy: " << i << endl;
                impdone[i] = true;
                f = true;
            }
        }
    }
    cout << ans << endl;
}
