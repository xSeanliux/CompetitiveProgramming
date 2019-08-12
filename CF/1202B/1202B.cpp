#include <iostream>
#include <queue>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int ways[10][10][10][10];

inline int add(int a, int b){
    return (a + b) % 10;
}

inline int sub(int a, int b){
    return (a - b + 100) % 10;
}

void initways(){
    queue<int> q;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <= i; j++){
            bool visited[10];
            for(int k = 0; k < 10; k++){
                for(int l = 0; l < 10; l++){
                    visited[l] = false;
                    ways[i][j][k][l] = -1;
                }
                ways[i][j][k][add(k, i)] = 1;
                ways[i][j][k][add(k, j)] = 1;
                q = queue<int>();
                q.push(add(k, i));
                q.push(add(k, j));
                visited[add(k, i)] = true;
                visited[add(k, j)] = true;
                while(q.size()){
                    int t = q.front();
                    q.pop();
                    if(!visited[ add(t, i) ]){
                        ways[i][j][k][add(t, i)] = ways[i][j][k][t] + 1;
                        q.push(add(t, i));
                        visited[add(t,i)] = true;
                    }
                    if(!visited[ add(t, j) ]){
                        ways[i][j][k][add(t, j)] = ways[i][j][k][t] + 1;
                        q.push(add(t, j));
                        visited[add(t,j)] = true;
                    }
                }
            }
            if(i != j){
                for(int k = 0; k < 10; k++){
                    for(int l = 0; l < 10; l++){
                        ways[j][i][k][l] = ways[i][j][k][l];
                    }
                }
            }
        }
    }
}

string s;
int a, b, c, d;
int main(){
    ericxiao;
    initways();
    cin >> s;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int ans = 0;
            bool flg = true;
            for(int k = 1; k < s.length(); k++){
                if(ways[i][j][ s[k - 1] - '0' ][ s[k] - '0' ] == -1){
                    cout << -1 << " ";
                    flg = false;
                    break;
                } else {
                    ans += ways[i][j][ s[k - 1] - '0' ][ s[k] - '0' ] - 1;
                }
            }
            if(flg)
                cout << ans << " ";
        }
        cout << '\n';
    }
}
