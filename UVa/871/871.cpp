#include <iostream>
#include <string.h>
using namespace std;

int c, blobs, height;
string str;
string t;
bool arr[30][30];
void dfs(int y, int x){
    if(arr[y][x] == 0 || y >= height){
        return;
    } else {
        //cout << y << ", " << x << endl;
        arr[y][x] = 0;
        blobs++;
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(i != 0 || j != 0)
                    dfs(y + i, x + j);
            }
        }
    }
}

int main(){
    cin >> c;
    getline(cin, t);
    getline(cin, t);
    for(int isas = 0; isas < c; isas++){

        getline(cin, str);
        for(int i = 0; i < 30; i++){
            for(int j = 0; j < 30; j++){
                arr[i][j] = 0;
            }
        }

        int N = str.length();

        for(int i = 1; i <= N; i++){
            arr[1][i] = str[i-1] - '0';
        }
        height = 2;
        while(str != ""){
            getline(cin, str);
            for(int j = 1; j <= N; j++){
                arr[height][j] = str[j-1] - '0';
            }
            height++;
        }
        height -= 1;
        /*
        cout << "Height = " << height << endl;
        for(int i = 1; i < height; i++){
            for(int j = 1; j <= N; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        */
        int maxBlobs = 0;
        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= N; j++){
                blobs = 0;
                if(arr[i][j]){
                    //cout << "New!" << endl;
                    dfs(i, j);
                    if(blobs >= maxBlobs){
                        maxBlobs = blobs;

                    }
                }
            }
        }
        blobs = 0;
        if(isas) cout << endl;
        cout << maxBlobs << endl;
    }
}
