#include <iostream>
#include <stack>
#include <iomanip>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10;

struct Seg{
    int sum, amt;
    Seg(){}
    Seg(int x): sum(x), amt(1){}
    Seg(int s, int a): sum(s), amt(a){}
    bool operator<(const Seg &s){
        return sum * s.amt <= s.sum * amt;
    }
    Seg operator+(const Seg &s){
        return Seg(sum + s.sum, amt + s.amt);
    }
} seg;

stack<Seg> stk;

int N, x;
double ans[maxN];

signed main(){
    cout << fixed << setprecision(10);
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        seg = Seg(x);
        while(stk.size() && seg < stk.top()){
            seg = seg + stk.top();
            stk.pop();
        }
        stk.push(seg);
    }
    int cnt = N - 1;
    while(stk.size()){
        seg = stk.top();
        stk.pop();
        for(int i = 0; i < seg.amt; i++) ans[cnt - i] = seg.sum * 1.0 / seg.amt;
        cnt -= seg.amt;
    }
    for(int i = 0; i < N; i++) cout << ans[i] << '\n';
}
