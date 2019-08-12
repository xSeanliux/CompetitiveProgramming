#include <iostream>
#include <string.h>
using namespace std;

int arr[9][9];
string s;

void output(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << arr[i][j];
            if(j % 3 == 2) cout << " ";
        }
        cout << endl;
    }
}

bool check(int y, int x){
    //cout << "Checking y = " << y << ", x = " << x << "arr[y][x] = " << arr[y][x] << endl;
    //cout << endl;
    //output();
    //cout << endl;
    bool hasAlready[11];
    for(int i = 0; i <= 9; i++) hasAlready[i] = false;
    for(int i = 0; i < 9; i++){
        if(arr[i][x] && !hasAlready[arr[i][x]]) hasAlready[arr[i][x]] = true;
        else if (hasAlready[arr[i][x]]) {
            //cout << "Fail at y = " << i << ", x = " << x << endl;
            return false;
        }
    }
    for(int i = 1; i <= 9; i++) hasAlready[i] = false;
    for(int i = 0; i < 9; i++){
        if(arr[y][i] && !hasAlready[arr[y][i]]) hasAlready[arr[y][i]] = true;
        else if (hasAlready[arr[y][i]]) {
            //cout << "Fail at y = " << y << ", x = " << i << endl;
            return false;
        }
    }
    for(int i = 0; i <= 9; i++) hasAlready[i] = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[ y/3 * 3 + i ][ x/3 * 3 + j ] && !hasAlready[arr[ y/3 * 3 + i ][ x/3 * 3 + j ]]) {
                hasAlready[arr[ y/3 * 3 + i ][ x/3 * 3 + j ]] = true;
                //cout << "checked : " << arr[ y/3 * 3 + i ][ x/3 * 3 + j ] << endl;
            }
            else if (hasAlready[arr[ y/3 * 3 + i ][ x/3 * 3 + j ]]) {
                //cout << "Fail at y = " << y/3 * 3 + i << ", x = " << x/3 * 3 + j << "val = " << arr[ 3 * y/3 + i ][ 3 * x/3 + j ] << endl;
                return false;
            }
        }
    }
    return true;
}

bool dfs(int y, int x){
    if(arr[y][x]){
        if(!check(y, x)) return false;
        if(x == 8 && y == 8) return true;
        if(x == 8) return dfs(y + 1, 0);
        return dfs(y, x + 1);
    }
    for(int i = 1; i <= 9; i++){
        arr[y][x] = i;
        if(check(y, x)){
            if(x == 8 && y == 8) return true;
            else if(x == 8 && dfs(y + 1, 0)) return true;
            else if (dfs(y, x + 1)) return true;
        }
    }
    arr[y][x] = 0;
    return false;

}

int main(){
    while(cin >> s){
        if(s == "end") return 0;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(s[9*i + j] == '.') arr[i][j] = 0;
                else arr[i][j] = s[9*i + j] - '0';
            }
        }
        if(dfs(0, 0)){
            //cout << "ANS" << endl;
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    cout << arr[i][j];
                }
                cout << endl;
            }
            cout << endl;
        } else {
            cout << "No solution." << endl;
        }
    }
}
