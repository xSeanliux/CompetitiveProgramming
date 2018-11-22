#include <iostream>
#include <string.h>
using namespace std;

int arr[5], _a[5];
char ops[4];
bool isPossible, visited[15];
int parse(){
    int res = _a[0];
    for(int i = 0; i < 4; i++){
        if(ops[i] == '*'){
            res *= _a[i+1];
        } else if(ops[i] == '+'){
            res += _a[i+1];
        } else if(ops[i] == '-'){
            res -= _a[i+1];
        }
    }
    /*
    cout << arr[0];
    for(int i = 0; i < 4; i++){
        cout << " " << ops[i] << " " << _a[i + 1];
    }
    cout << " = " << res << endl;
    */
    return res;
}


void dfs2(int iteration){
    if(iteration == 4){
        if(!isPossible && parse() == 23){
            isPossible = true;
        }
        return;
    } else {
        ops[iteration] = '+';
        dfs2(iteration + 1);
        ops[iteration] = '-';
        dfs2(iteration + 1);
        ops[iteration] = '*';
        dfs2(iteration + 1);
        return;
    }
}

void dfs1(int iteration){
    if(iteration == 5){
        if(!isPossible)
            dfs2(0);
        return;
    } else {
        for(int i = 0; i < 5; i++){
            if(!visited[i]){
                _a[iteration] = arr[i];
                visited[i] = true;
                dfs1(iteration + 1);
                visited[i] = false;
            }
        }
    }
}

int s;
int main(){
    while(cin >> arr[0]){
        isPossible = false;
        s = arr[0];
        for(int i = 1; i < 5; i++){
            cin >> arr[i];
            s += arr[i];
        }
        if(s == 0) return 0;
        memset(visited, false, sizeof(visited));
        dfs1(0);
        if(isPossible){
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }
}
