#include <iostream>
#include <string.h>
using namespace std;

int N, ans, c = 0;
bool M[30][30];
string s;


int dfs(int y, int x){
    //cout << "Running dfs(" << y << ", " << x << ")" << endl;
    if(y < 0 || y >= N || x < 0 || x >= N || !M[y][x])
        return 0;
    M[y][x] = 0;
    //cout << "yes" << endl;
    for(int i = -1 ; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            dfs(y + i, x + j);
        }
    }
    return 1;
}


int main(){
    while(cin >> N){
        ans = 0;
        for(int i  = 0 ; i < N; i++){
            cin >> s;
            for(int j = 0 ; j < N;j++){
                M[i][j] = s[j] - '0';
                //cout << "M[" << i << "][" << j << "] = s[" << j << "] = " << s[j] << endl;
            }
        }
        /*
        cout << endl;
        for(int i  = 0 ; i < N; i++){
            for(int j = 0 ;j  < N;j++){
                cout << M[i][j];
            }
            cout << endl;
        }
        */
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < N;j++){
                //if(M[i][j]) cout << "Found eagle" << endl;
                ans += dfs(i, j);
            }
        }
        printf("Image number %d contains %d war eagles.\n", ++c, ans);
    }
}
