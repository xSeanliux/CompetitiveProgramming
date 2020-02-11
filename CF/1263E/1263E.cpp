#include <iostream>
#include <string.h>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2262500, INF = 1e6;

pii res;
string com, s;
int curpos = 0, n, maxval = 0, lastans = 0, sum = 0;

struct Node{
    int maxval, minval, tag;
    Node(){
        tag = maxval = minval = 0;
    }
} seg[maxN * 2];

inline void push(int id, int l, int r){
    seg[id].minval += seg[id].tag;
    seg[id].maxval += seg[id].tag;
    if(l + 1 < r){
        seg[2 * id + 1].tag += seg[id].tag;
        seg[2 * id + 2].tag += seg[id].tag;
    }
    seg[id].tag = 0;
}
inline void pull(int id){
    seg[id].maxval = max(seg[2 * id + 1].maxval, seg[2 * id + 2].maxval);
    seg[id].minval = min(seg[2 * id + 1].minval, seg[2 * id + 2].minval);
}

void modify(int id, int l, int r, int ql, int qr, int val){
    push(id, l, r);
    if(l >= qr || ql >= r) return;
    if(ql <= l && r <= qr){
        seg[id].tag += val;
        push(id, l, r);
        return;
    }
    int m = (l + r) / 2;
    modify(2 * id + 1, l, m, ql, qr, val);
    modify(2 * id + 2, m, r, ql, qr, val);
    pull(id);
}

pii query(int id = 0, int l = 0, int r = n, int ql = 0, int qr = n){
    push(id, l, r);
    if(l >= qr || ql >= r) return {INF, -INF};
    if(ql <= l && r <= qr) return {seg[id].minval, seg[id].maxval};
    int m = (l + r) / 2;
    pii lft = query(2 * id + 1, l, m, ql, qr);
    pii rgt = query(2 * id + 2, m, r, ql, qr);
    return {min(lft.F, rgt.F), max(lft.S, rgt.S)};
}

int main(){
    ericxiao;
    cin >> n >> com;
    for(int i = 0; i < n; i++){
        s += ' ';
    }
    for(char ch : com){
        if(ch == 'L' || ch == 'R'){
            curpos += (ch == 'L' ? -1 : 1);
            if(curpos == -1) curpos = 0;
            maxval = max(curpos, maxval);
            cout << lastans << " ";
            continue;
        }

        if(s[curpos] == '('){
            sum--;
            modify(0, 0, n, curpos, n, -1);
        } else if(s[curpos] == ')'){
            sum++;
            modify(0, 0, n, curpos, n, 1);
        }
        s[curpos] = ch;
        if(s[curpos] == '('){
            sum++;
            modify(0, 0, n, curpos, n, 1);
        } else if(s[curpos] == ')'){
            sum--;
            modify(0, 0, n, curpos, n, -1);
        }

        //cout << s << " " ;
        //cout << "Query of [" << maxval << ", " << maxval + 1 << ") = " << getSum() << endl;
        res = query();
        if(!sum && !res.F){
            lastans = res.S;
        } else {
            lastans = -1;
        }
        cout << lastans << " ";
        //cout << endl;
    }
}
