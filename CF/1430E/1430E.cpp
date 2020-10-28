#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <deque>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326, W = 30;

string s, t;
int N, has[maxN];
deque<int> pos[W + 'a'];
set<int> all;
long long int ans;

struct BIT{
    int arr[maxN];
    BIT(){}
    BIT(int x){
        fill(arr, arr + x + 1, 0);
    }
    void modify(int p, int x){
        for(; p <= N + 1; p += p & -p) arr[p] += x;
    }
    int query(int p){
        int r = 0;
        for(; p; p -= p & -p) r += arr[p];
        return r;
    }
} bit;

int main(){
    cin >> N >> s;
    t = s;
    bit = BIT(N + 1);
    reverse(t.begin(), t.end());
    for(int i = 0; i < N; i++){
        pos[s[i]].push_back(i);
    }
    for(int i = 0; i < N; i++){
        int x = pos[t[i]].front();
        int y = x;
        pos[t[i]].pop_front();
        x += bit.query(N + 1) - bit.query(x + 1);
        bit.modify(y + 1, 1);
        ans += x - i;
    }
    cout << ans << endl;
}
