#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 2e5 + 326, maxK = 18;
int K, Q, x, wins[(1 << maxK)], l[(1 << maxK)], r[(1 << maxK)], pa[(1 << maxK)];
char c;
string s;

inline void pull(int id){
    if(id <= (1 << (K - 1))){
        wins[id] = 1 + (s[id] == '?');
        return;
    }
    if(s[id] == '0'){
        wins[id] = wins[l[id]];
    } else if(s[id] == '1'){
        wins[id] = wins[r[id]];
    } else {
        wins[id] = wins[l[id]] + wins[r[id]];
    }
}

inline void update(int id){
    while(id != (1 << K)){
        pull(id);
        //cout << "win[" << id << "] = " << wins[id] << endl;
        id = pa[id];
    }
}

inline void initTree(){
    for(int i = 1; i < (1 << K); i++){
        pa[(1 << K) - i] = (1 << K) - i / 2;
        l[(1 << K) - i] = (1 << K) - 2 * i - 1;
        r[(1 << K) - i] = (1 << K) - 2 * i;
    }
}

void init(int id = (1 << K) - 1){
    pull(id);
    if(id <= (1 << (K - 1))) return;
    init(l[id]);
    init(r[id]);
    pull(id);
}

int main(){
    cin >> K;
    initTree();
    for(int i = 1; i < (1 << K); i++){
        //cout << "l[" << i << "] = " << l[i] << ", r[" << i << "] = " << r[i] << ", pa[" << i << "] = " << pa[i] << endl;
    }
    cin >> s;
    s = '$' + s;
    init();
    for(int i = 1; i < (1 << K); i++){
        //cout << "wins[" << i << "] = " << wins[i] << endl;
    }
    cin >> Q;
    while(Q--){
        cin >> x >> c;
        s[x] = c;
        update(x);
        cout << wins[(1 << K) - 1] << endl;
    }
}
