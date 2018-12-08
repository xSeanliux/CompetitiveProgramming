#include <iostream>
using namespace std;

int scores[10][10], maxScore, N;
bool hasQueen[10][10];

bool isGood(int y, int x){
    bool isGood = true;
    for(int i = 0 ; i < 8; i++){
        if(hasQueen[i][x] || hasQueen[y][i]) return false;
    }
    for(int i = 1; x - i >= 0 && y + i < 8; i++){
        if(hasQueen[y + i][x - i]) return false;
    }
    for(int i = -1; x - i < 8 && y + i >= 0; i--){
        if(hasQueen[y + i][x - i]) return false;
    }
    for(int i = 1; x + i < 8 && y + i < 8; i++){
        if(hasQueen[y + i][x + i]) return false;
    }
    for(int i = -1; x + i >= 0 && y + i >= 0; i--){
        if(hasQueen[y + i][x + i]) return false;
    }
    return true;
}

void dfs(int now){
    if(now == 8){ //calculate sum
        int currentAns = 0;
        for(int i = 0 ; i < 8; i++){
            for(int j = 0; j < 8; j++)
                currentAns += (hasQueen[i][j] * scores[i][j]);
        }
        maxScore = max(maxScore, currentAns);
    } else {
        for(int i = 0 ; i < 8; i++){
            if(isGood(i, now)){
                hasQueen[i][now] = true;
                dfs(now + 1);
                hasQueen[i][now] = false;
            }
        }
    }
}


int main(){
    cin >> N;
    while(N--){
        maxScore = 0;
        for(int i = 0 ; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin >> scores[i][j];
                hasQueen[i][j] = 0;
            }
        }
        dfs(0);
        printf("%5d\n", maxScore);
    }
}
