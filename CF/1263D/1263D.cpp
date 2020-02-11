#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 226;

int dsu[maxN], n, ans = 0;
string s;

void flat(int x){
    if(dsu[x] == x) return;
    flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void merge(char a, char b){
    if(dsu[a] == -1){
        dsu[a] = a;
        ans++;
    }
    if(dsu[b] == -1){
        dsu[b] = b;
        ans++;
    }
    flat(a);
    flat(b);
    if(dsu[a] == dsu[b]) return;
    ans--;
    dsu[dsu[a]] = dsu[b];
    flat(a);
    flat(b);
}

int main(){
    cin >> n;
    fill(dsu, dsu + maxN, -1);
    while(n--){
        cin >> s;
        merge(s[0], s[0]);
        for(int i = 1; i < s.length(); i++){
            merge(s[0], s[i]);
        }
    }
    cout << ans << endl;
}
