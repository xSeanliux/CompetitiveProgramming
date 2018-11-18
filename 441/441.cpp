#include <iostream>
using namespace std;

int go[6], arr[15], N;
bool visited[15];

void dfs(int now){
    if(now == 6){
        for(int i = 0 ; i < 6; i++){
            if(i != 0) cout << " ";
            cout << go[i];
        }
        cout << endl;
        return;
    } else {
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                visited[i] = true;
                go[now] = arr[i];
                dfs(now + 1);
                visited[i] = false;

            }
        }
        return;
    }
}


int main(){
    while(cin >> N){
        if(!N) return 0;
        for(int i = 0 ; i < N; i++){
            cin >> arr[i];
            visited[i] = false;
        }
        dfs(0);
    }
}
