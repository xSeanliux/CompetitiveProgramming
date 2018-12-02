#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w, h, cnt, c = 0;
char pic[55][55];

void dfs2(int y, int x){
    if(y < 0 || x < 0 || x >= w || y >= h || pic[y][x] != 'X')
        return;
    pic[y][x] = '*';
    dfs2(y + 1, x);
    dfs2(y - 1, x);
    dfs2(y, x + 1);
    dfs2(y, x - 1);
}

void dfs(int y, int x){
    if(y < 0 || x < 0 || x >= w || y >= h || pic[y][x] == '.')
        return;
    if(pic[y][x] == 'X'){
            cnt++;
            dfs2(y, x);
    }
    pic[y][x] = '.';
    dfs(y + 1, x);
    dfs(y - 1, x);
    dfs(y, x + 1);
    dfs(y, x - 1);
}


int main(){
    while(cin >> w >> h){
        if(!w && !h) return 0;
        vector <int> rolls;
        for(int i = 0 ; i < h; i++)
            for(int j = 0 ; j < w; j++)
                cin >> pic[i][j];
        cnt = 0;
        for(int i = 0 ; i < h; i++)
            for(int j = 0 ; j < w; j++){
                if(pic[i][j] != '.'){
                    cnt = 0;
                    dfs(i, j);
                    rolls.push_back(cnt);
                    //cout << cnt << endl;
                }
            }
        sort(rolls.begin(), rolls.end());
        printf("Throw %d\n", ++c);
        for(int i = 0 ; i < rolls.size(); i++){
            cout << rolls[i];
            if(i < rolls.size() - 1) cout << " ";
        }
        cout << endl << endl;
    }
}
