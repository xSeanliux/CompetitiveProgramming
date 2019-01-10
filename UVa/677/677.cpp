#include <iostream>
#include <string>
using namespace std;

int arr[14][14];
bool vis[14];
int paths[10];
int N, len, npaths;

void dfs(int currentNode , int now){

    paths[now] = currentNode;


    //cout << endl << "END OF PRINTING ARR" << endl;
    if(now == len){
        npaths++;
        cout << "(";
        for(int i = 0; i <= len ; i++){
            printf("%d", paths[i]+1);
            if(i < len) printf(",");

        }
        cout << ")" << endl;
        return;
    }

    for(int i = 1; i < N; i++){
        if(arr[currentNode][i] == 1 && !vis[i]){ //important bit, use a visited array
            vis[i] = true;
            dfs(i, now+1);
            vis[i] = false;

        }
    }
    return;

}



int main(){
    while(cin >> N >> len){

        for(int i = 0 ; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
            }
            vis[i] = false;
        }

        for(int i = 0 ; i < len; i++){
            paths[i] = 90;
        }

        npaths = 0;
        vis[0] = true;
        dfs(0 , 0);
        if(!npaths) cout << "no walk of length " << len << endl;
        string k;
        getline(cin, k);
        if(cin.peek() == '-'){
            int t;
            cin >> t;
            cout << endl;
        }
    }

}
