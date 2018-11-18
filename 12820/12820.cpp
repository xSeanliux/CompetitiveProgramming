#include <iostream>
#include <string.h>
#include <map>
#include <set>
using namespace std;

string s;
int t, c, k = 0;
map <char, int> o;
set <int> p;

bool isCool(string S){
    o = map<char, int>();
    p = set<int>();
    int l = S.length();
    for(int i = 0; i < l; i++){
        if(o.count(S[i])){
            o[S[i]]++;
        } else {
            o.insert(pair<char, int>(S[i], 0));
        }
    }
    for(auto x = o.begin(); x != o.end(); x++){
        if(p.count(x->second))
            return false;
        p.insert(x->second);
    }
    if(p.size() >= 2) return true;
    return false;
}



int main(){
    while(cin >> t){
        c = 0;
        for(int i = 1; i <= t; i++){
            cin >> s;
            c += isCool(s);
        }
        printf("Case %d: %d\n", ++k, c);

    }
}
