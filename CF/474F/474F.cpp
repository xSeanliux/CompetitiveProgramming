#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 100005, INF = 2e9;

int arr[maxN], seg[maxN * 4][2], N, Q, l, r;

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

void build(int id, int l, int r){
    if(l + 1 == r){
        seg[id][0] = seg[id][1] = arr[l];
        return;
    }
    build(2 * id + 1, l, (l + r) / 2);
    build(2 * id + 2, (l + r) / 2, r);
    seg[id][0] = min(seg[2 * id + 1][0], seg[2 * id + 2][0]);
    seg[id][1] = gcd(seg[2 * id + 1][1], seg[2 * id + 2][1]);
}

int getmin(int id, int ql, int qr, int l, int r){
    if(r <= ql || l >= qr) return INF;
    if(ql <= l && r <= qr) return seg[id][0];
    return min(getmin(2 * id + 1, ql, qr, l, (l + r)/2), getmin(2 * id + 2, ql, qr, (l + r) / 2, r));
}

int getgcd(int id, int ql, int qr, int l, int r){
    if(r <= ql || l >= qr) return 0;
    if(ql <= l && r <= qr) return seg[id][1];
    return gcd(getgcd(2 * id + 1, ql, qr, l, (l + r)/2), getgcd(2 * id + 2, ql, qr, (l + r) / 2, r));
}

map<int, vector<int> > mp;

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    cin >> Q;
    build(0, 0, N);
    int g, m, u, d;
    while(Q--){
        cin >> l >> r;
        g = getgcd(0, l - 1, r, 0, N);
        m = getmin(0, l - 1, r, 0, N);
        if(g == m){
            //cout << "G = M = " << g << endl;
            u = upper_bound(mp[g].begin(), mp[g].end(), r - 1) - mp[g].begin();
            d = upper_bound(mp[g].begin(), mp[g].end(), l - 2) - mp[g].begin();
            //cout << "There are " << u << " occurences less than or equal to pos " << r - 1 << endl;
            //cout << "There are " << d << " occurences less than or equal to pos " << l - 2 << endl;
            cout << (r - l + 1) - (u - d) << endl;
        } else {
            cout << (r - l + 1) << endl;
        }
    }
}
