#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N, a, b, t;

priority_queue <int> priq;
queue<int> que;
stack<int> stk;

int main(){
    while(cin >> N){
        priq = priority_queue<int>();
        que = queue<int>();
        stk = stack<int>();
        bool isPriq = true, isQue = true, isStk = true;
        while(N--){
            scanf("%d %d", &a, &b);
            if(a == 1){
                if(isPriq){
                    priq.push(b);
                }
                if(isQue){
                    que.push(b);
                }
                if(isStk){
                    stk.push(b);
                }
            } else {
                if(priq.empty()) {
                    isPriq = false;
                } else if (isPriq){
                    t = priq.top();
                    if(t == b){
                        priq.pop();
                    } else {
                        isPriq = false;
                    }
                }
                if(que.empty()){
                    isQue = false;
                } else if(isQue){
                    t =  que.front();
                    if(t == b){
                        que.pop();
                    } else {
                        isQue = false;
                    }
                }
                if(stk.empty()){
                    isStk = false;
                } else if(isStk){
                    t = stk.top();
                    if(t == b){
                        stk.pop();
                    } else {
                        isStk = false;
                    }
                }
            }
        }
        if(!((int)isPriq + (int)isStk + (int)isQue)){
            printf("impossible\n");
        } else if(((int)isPriq + (int)isStk + (int)isQue) > 1){
            printf("not sure\n");
        } else {
            if(isPriq){
                printf("priority queue\n");
            } else if(isStk) {
                printf("stack\n");
            } else {
                printf("queue\n");
            }
        }
    }
}

