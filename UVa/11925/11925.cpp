#include <iostream>
#include <deque>
using namespace std;

int N, k, _t, a, b;

void printque(deque <int> que){
    for(int i : que){
        printf("%d ", i);
    }
    cout << endl;
}

int cnt = 0;

void go(int N){
    if(!N) return;
    deque <int> que;
    int f[301];
    for(int i = 1; i <= N; i++){
        cin >> k;
        f[k] = i;
        //printf("f[%d] = %d\n", k, i);
    }
    for(int i = 1; i <= N; i++){
        que.push_back(f[i]);
        //cout << f[i] << " ";
    }
    //cout << endl;
    for(int i = N-1; i >= 1; i--){
        while(que.front() != i){
            printf("2");
            cnt++;
            que.push_back(que.front());
            que.pop_front();
        }
        //printf("\n");
        //printque(que);
        a = que.front();
        que.pop_front();
        b = que.front();
        que.push_front(a);
        while(b != i + 1){
            printf("12");
            cnt += 2;
            que.push_back(b);
            //printque(que);
            que.pop_front();
            que.pop_front();
            que.push_front(a);
            //printque(que);
            a = que.front();
            que.pop_front();
            b = que.front();
            que.push_front(a);
            //printque(que);
        }
    }
    printf("\n");
    //cout << "cnt: " << cnt << " limit: " << 2*N*N << endl;
}

int main(){
    while(cin >> N){
        if(!N) return 0;
        go(N);
    }
}
