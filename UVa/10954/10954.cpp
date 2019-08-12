#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main(){
    while(scanf("%d", &N) != EOF){
        if(!N) return 0;
        priority_queue<int, vector<int>, greater<int> > que;
        int _t, res = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &_t);
            que.push(_t);
        }
        int t1, t2;
        while(que.size() > 1){
            t1 = que.top();
            que.pop();
            t2 = que.top();
            que.pop();
            res += (t1 + t2);
            que.push(t1 + t2);
        }
        printf("%d\n", res);
    }
}
