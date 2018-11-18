#include <iostream>
#include <string.h>
using namespace std;

int c, H, N;
bool visited[20];
string s;
void dfs(int ite, int fin){
    if(ite == N){
        for(int i = 0 ; i < H; i++){
            cout << visited[i];
        }
        cout << endl;
        return;
    } else {
        for(int i = fin ; i < H; i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(ite + 1, i);
                visited[i] = false;
            }
        }
    }
}


int main(){
    cin >> c;

    for(int i = 0 ; i < c; i++){
        s = "";
        cin >> H >> N;
        dfs(0, 0);
    }
}
