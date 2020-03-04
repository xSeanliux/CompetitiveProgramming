#include <iostream>
#include <stack>
#define int long long int
using namespace std;

const int maxN = 5e5 + 10;

int lim[maxN], rig[maxN], lft[maxN], N, sum, mx = 0, mxAt, ans[maxN];

struct Obj{
    int l, r, i;
    Obj(){}
    Obj(int i, int p): l(p), r(p), i(i){}
} currentObj;

stack<Obj> stk;

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> lim[i];
    }
    for(int i = 0; i < N; i++){
        currentObj = Obj(i, i);
        while(stk.size() && lim[stk.top().i] >= lim[i]){
            currentObj.l = stk.top().l;
            sum -= (stk.top().r - stk.top().l + 1) * (lim[stk.top().i]);
            stk.pop();
        }
        stk.push(currentObj);
        sum += (currentObj.r - currentObj.l + 1) * (lim[i]);
        lft[i] = sum;
    }
    sum = 0;
    stk = stack<Obj>();
    for(int i = N - 1; i >= 0; i--){
        currentObj = Obj(i, i);
        while(stk.size() && lim[stk.top().i] >= lim[i]){
            currentObj.r = stk.top().r;
            sum -= (stk.top().r - stk.top().l + 1) * (lim[stk.top().i]);
            stk.pop();
        }
        stk.push(currentObj);
        sum += (currentObj.r - currentObj.l + 1) * (lim[i]);
        rig[i] = sum;
    }

    //for(int i = 0; i < N; i++){
    //    cout << "lft[" << i << "] = " << lft[i] << ", rgt[i] = " << rig[i] << endl;
    //}



    for(int i = 0; i < N; i++){
        if(mx < lft[i] + rig[i] - lim[i]){
            mx = lft[i] + rig[i] - lim[i];
            mxAt = i;
        }
    }

    ans[mxAt] = lim[mxAt];
    stk = stack<Obj>();
    for(int i = 0; i <= mxAt; i++){
        currentObj = Obj(i, i);
        while(stk.size() && lim[stk.top().i] >= lim[i]){
            currentObj.l = stk.top().l;
            stk.pop();
        }
        stk.push(currentObj);
    }
    while(stk.size()){
        for(int i = stk.top().l; i <= stk.top().r; i++) ans[i] = lim[stk.top().i];
        stk.pop();
    }
    stk = stack<Obj>();
    for(int i = N - 1; i >= mxAt; i--){
        currentObj = Obj(i, i);
        while(stk.size() && lim[stk.top().i] >= lim[i]){
            currentObj.r = stk.top().r;
            stk.pop();
        }
        stk.push(currentObj);
    }
    while(stk.size()){
        for(int i = stk.top().l; i <= stk.top().r; i++) ans[i] = lim[stk.top().i];
        stk.pop();
    }
    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}
