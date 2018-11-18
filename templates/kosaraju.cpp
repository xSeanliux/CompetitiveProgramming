#include <iostream>
#define MAX 1000
using namespace std;

int N, conns, arr[MAX], head = 0, a, b;
bool cons[MAX][MAX], rev[MAX][MAX], visited[MAX];

void push(int n){
    arr[head] = n;
    head++;
}

void dfs(int ind){
    for(int i = 1 ; i <= N; i++){
        if(cons[ind][i] && !visited[i]){
            visited[i] = true;
            push(i);
            dfs(i);
            push(i);
        }
    }
}

void dfs2(int ind){
    for(int i = 1 ; i <= N; i++){
        if(rev[ind][i] && !visited[i]){
            cout << " " << i;
            visited[i] = true;
            dfs2(i);
        }
    }
}


int main(){
    cin >> N;
    for(int i = 1 ; i <= N; i++){
        visited[i] = false;
        for(int j = 1 ; j <= N; j++){
            cons[i][j] = rev[i][j] = false;
        }
    }
    cin >> conns;
    for(int i = 0 ; i < conns; i++){
        cin >> a >> b;
        cons[a][b] = rev[b][a] = true;
    }
    for(int i = 1 ; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            push(i);
            dfs(i);
            push(i);
        }
    }

    cout << "b" << endl;
    //rev
    for(int i = 1 ; i <= N; i++){
        visited[i] = false;
    }
    for(int i = 0 ; i < head; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    for(int i = head - 1; i >= 0; i--){
        if(!visited[arr[i]]){
            visited[arr[i]] = true;
            //cout << "New component: " << arr[i];
            dfs2(arr[i]);
            cout << endl;
        }
    }

}
