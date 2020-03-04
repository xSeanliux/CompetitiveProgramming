#include <iostream>
#include <unordered_set>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int maxN = 4e5 + 10;

int l[maxN], r[maxN], val[maxN], pri[maxN], sz[maxN], root = -1, cnt = 0, seed = 101;



void disp(int x){
    if(x == -1) return;
    disp(l[x]);
    cout << val[x] << " ";
    disp(r[x]);
}

inline int Rand(){
    return seed = (seed * 3 + 101) % 2147483647;
}

inline int Sz(int x){
    return ~x ? sz[x] : 0;
}

int newNode(int x){
    int o = cnt++;
    l[o] = r[o] = -1;
    pri[o] = Rand();
    val[o] = x;
    sz[o] = 1;
    return o;
}

void pull(int id){
    sz[id] = Sz(l[id]) + Sz(r[id]) + 1;
}

int Merge(int a, int b){
    if(!(~a) || !(~b)) return ~a ? a : b;
    if(pri[a] < pri[b]){
        r[a] = Merge(r[a], b);
        pull(a);
        return a;
    } else {
        l[b] = Merge(a, l[b]);
        pull(b);
        return b;
    }
}

void Split(int o, int &a, int &b, int k){
    if(!(~o)){
        a = b = o;
        return;
    }
    if(val[o] <= k){
        a = o;
        Split(r[o], r[a], b, k);
        pull(a);
    } else {
        b = o;
        Split(l[o], a, l[b], k);
        pull(b);
    }
}

void Ins(int x){
    int a, b, c;
    Split(root, a, b, x);
    root = Merge(Merge(a, newNode(x)), b);
}

void Del(int x){
    int a, b, c, d;
    Split(root, a, b, x);
    Split(a, c, d, x - 1);
    root = Merge(c, b);
}

int getKth(int k){
    int cur = root;
    while(true){
        if(Sz(l[cur]) + 1 == k) return val[cur];
        if(k <= Sz(l[cur])){
            cur = l[cur];
        } else {
            k -= Sz(l[cur]) + 1;
            cur = r[cur];
        }
    }
}

int N, x, totnums = 0;
unordered_set<int> st;
string s;




signed main(){
    ericxiao;
    cin >> N;
    while(N--){
        cin >> s >> x;
        if(s[0] == 'a'){ //add
            if(!st.count(x)){
                Ins(x);
                st.insert(x);
            }
        } else if(s[0] == 'q'){
            cout << getKth(x) << endl;
        } else {
            if(st.count(x)){
                Del(x);
                st.erase(x);
            }
        }
        //disp(root);
        //cout << endl;
    }
}
