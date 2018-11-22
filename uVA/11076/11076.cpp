#include <iostream>
#include <math.h>
using namespace std;

int N, arr[100], nowa[100], ans;
bool visited[100];

int f(){
    int r = 0;
    for(int i = 0; i < N; i++){
        r += pow(10, i) * nowa[i];
    }
    return r;
}

void dfs(int now){
    if(now == N){
        for(int i = 0; i < N; i++){
            cout << nowa[i] << " ";
        }
        cout << endl;
        ans += f();
    } else {
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                visited[i] = true;
                nowa[now] = arr[i];
                dfs(now + 1);
                visited[i] = false;
            }
        }
    }
}


int main(){
    while(cin >> N){
        if(!N) return 0;
        ans = 0;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            visited[i] = false;
        }
        dfs(0);
        cout << ans << endl;
    }
}

