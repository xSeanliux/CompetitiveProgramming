#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

const int maxN = 3e5 + 10;

stack<int> stk;
vector<int> ops;
int toundo[maxN];
bool state[maxN];
int N, x;

inline int Abs(int x){
    return (x < 0 ? -x : x);
}


void disp(int x){
    for(int i = 0; i < x; i++) cout << state[i] << " ";
    cout << endl;
}

/*
11
1
2
5
-1
-1
-3
4
-2
-1
-1
1
*/

int main(){
    cin >> N;
    if(N <= maxN){
        ops.push_back(0);
        while(N--){
            cin >> x;
            ops.push_back(x);
            if(x > 0){
                state[ops.size() - 1] = 1;
            } else {
                for(int i = ops.size() - 1; i >= 0; i--){
                    if(state[i] && (ops[i] > 0 || Abs(ops[i]) < Abs(x))){
                        toundo[ops.size() - 1] = i;
                        //cout << "toundo = " << i << endl;
                        break;
                    }
                }
                int cur = ops.size() - 1;
                while(cur){
                    state[cur] ^= 1;
                    if(ops[cur] >= 0) break;
                    cur = toundo[cur];
                }
            }
            //cout << "J" << endl;
            int ans = 0;
            for(int i = ops.size() - 1; i >= 0; i--){
                if((state[i] && ops[i] >= 0) || !i){
                    cout << ops[i] << endl;
                    break;
                }
            }
            //disp(ops.size());
        }
        return 0;
    } else {
        stk.push(0);
        bool f = true;
        while(N--){
            cin >> x;
            ops.push_back(x);
            if(x < -1) f = false;

        }
        if(f){
            for(int x : ops){
                if(x > 0) stk.push(x);
                else stk.pop();
                cout << stk.top() << endl;
            }
        } else {
            stack<int> dd;
            vector<int> adj[maxN];
            queue<int> que;
            int indeg[maxN], covertime[maxN];
            dd.push(0);
            for(int i = 0; i < N; i++){
                if(ops[i] >= 0){
                    dd.push(i);
                    continue;
                }
                while(dd.size() && ops[dd.top()] < ops[i]) dd.pop();
                if(ops[dd.top()] == ops[i]){
                    toundo[i] = toundo[dd.top()];
                    adj[i].push_back(toundo[dd.top()]);
                } else {
                    toundo[i] = dd.top();
                    stk.push(i);
                    adj[i].push_back(dd.top());
                }
                indeg[toundo[i]]++;
            }
            for(int i = 0; i < N; i++){
                if(!indeg[i]){
                    covertime[i] = 1;
                    que.push(i);
                }
            }
            while(que.size()){
                int t = que.front();
                que.pop();
                for(int v : adj[t]){
                    covertime[v] = covertime[v] + covertime[t]; //+ % 2
                    indeg[v]--;
                    if(!indeg[v]) que.push(v);
                }
            }
            int lastans = 0;
            for(int i = N - 1; i >= 0; i--){
                if(ops[i] >= 0 && covertime[i] % 2){
                    lastans = ops[i];
                    break;
                }
            }
            for(int i = 0; i < N - 1; i++) cout << 0 << endl;
            cout << lastans << endl;
        }
    }

}
