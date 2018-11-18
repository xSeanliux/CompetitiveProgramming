#include <iostream>
using namespace std;

bool canStay[15][15];
int pieces, x, y, genX, genY;
char type;
char board[15][15];

void toggle(int y, int x){
    if(y <= 10 && x <= 10 && x > 0 && y > 0)
        canStay[y][x] = false;
}

bool checkCanEscape(int y, int x){
    return(y >= 4 && y <= 6 && x >= 1 && x <= 3 && canStay[y][x]);
}


int main(){
    while(cin >> pieces >> genX >> genY){
        if(!pieces && !genX && !genY) return 0;
        for(int i = 1; i <= 10; i++){
            for(int j = 1 ; j <= 10; j++){
                canStay[i][j] = true;
                board[i][j] = '-';
            }
        }
        board[genY][genX] = 'g';
        for(int i = 0; i < pieces; i++){
            cin >> type >> x >> y;
            board[y][x] = type;
        }
        for(int i = 1; i <= 10; i++){
            for(int j = 1 ; j <= 10; j++){
                if(board[i][j] != 'g' && board[i][j] != '-'){ //time to move
                    char c = board[i][j]; //coords (x, y) = (j, i)
                    if(c == 'G'){ //general
                        bool hasIntervene = false;
                        for(int k = 10; k > 0; k--){
                            if(board[i][k] != '-' && board[i][k] != 'G' && board[i][k] != 'g'){
                                //cout << "has intervene " << endl;
                                hasIntervene = true;
                                break;
                            }
                        }
                        //cout << "no intervene" << endl;
                        if(!hasIntervene){
                            for(int k = 1; k <= 10; k++){
                                canStay[i][k] = false;
                            }
                        }
                    } else if(c == 'R'){ //chariot
                        for(int k = i + 1; k <= 10; k++){ //down
                            canStay[k][j] = false;
                            if(!(board[k][j] == '-' || board[k][j] == 'g'))
                                break;
                        }
                        for(int k = j + 1; k <= 10; k++){ //right
                            canStay[i][k] = false;
                            if(!(board[i][k] == '-' || board[i][k] == 'g'))
                                break;
                        }
                        for(int k = i - 1; k > 0; k--){ //down
                            canStay[k][j] = false;
                            if(!(board[k][j] == '-' || board[k][j] == 'g'))
                                break;
                        }
                        for(int k = j - 1; k > 0; k--){ //right
                            canStay[i][k] = false;
                            if(!(board[i][k] == '-' || board[i][k] == 'g'))
                                break;
                        }
                    } else if(c == 'H'){ //horse
                        if(board[i][j+1] == '-'){
                            toggle(i - 1, j + 2);
                            toggle(i + 1, j + 2);
                        }
                        if(board[i][j-1] == '-'){
                            toggle(i - 1, j - 2);
                            toggle(i + 1, j - 2);
                        }
                        if(board[i+1][j] == '-'){
                            toggle(i + 2, j - 1);
                            toggle(i + 2, j + 1);
                        }
                        if(board[i-1][j] == '-'){
                            toggle(i - 2, j - 1);
                            toggle(i - 2, j + 1);
                        }
                    } else if(c == 'C'){ //cannon
                        bool flag = false;
                        for(int k = i + 1; k <= 10 && !flag; k++){ //down
                            if(!(board[k][j] == '-' || board[k][j] == 'g')){
                                int l = k+1;
                                while(board[l][j] == '-' || board[l][j] == 'g'){
                                    canStay[l][j] = false;
                                    //board[l][j] = 'B';
                                    l++;
                                }
                                canStay[l][j] = false;
                                flag = true;
                                break;
                            }
                        }
                        flag = false;
                        for(int k = i - 1; k > 0 && !flag; k--){ //up
                            if(!(board[k][j] == '-' || board[k][j] == 'g')){
                                int l = k - 1;
                                while(board[l][j] == '-' || board[l][j] == 'g'){
                                    canStay[l][j] = false;
                                    //board[l][j] = 'B';
                                    l--;
                                }
                                canStay[l][j] = false;
                                flag = true;
                                break;
                            }
                        }
                        flag = false;
                        for(int k = j + 1; k <= 10 && !flag; k++){ //right
                            if(!(board[i][k] == '-' || board[i][k] == 'g')){
                                int l = k + 1;
                                while(board[i][l] == '-' || board[i][l] == 'g' && l <= 10){
                                    canStay[i][l] = false;
                                    //board[i][l] = 'B';
                                    l++;
                                }
                                canStay[i][l] = false;
                                flag = true;
                                break;
                            }
                        }
                        flag = false;
                        for(int k = j - 1; k > 0 && !flag; k--){ //left
                            if(!(board[i][k] == '-' || board[i][k] == 'g')){
                                int l = k - 1;
                                while(board[i][l] == '-' || board[i][l] == 'g' && l > 0){
                                    canStay[i][l] = false;
                                    //board[i][l] = 'B';
                                    l--;
                                }
                                canStay[i][l] = false;
                                flag = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        //bool isCM = !(checkCanEscape(genY + 1, genX) || checkCanEscape(genY - 1, genX) || checkCanEscape(genY, genX + 1) || checkCanEscape(genY, genX - 1) );
        //cout << checkCanEscape(genY + 1, genX) << ", " << checkCanEscape(genY - 1, genX) << ", "  << checkCanEscape(genY, genX + 1) << ", "  << checkCanEscape(genY, genX - 1) << endl;
        bool isCM = true;
        if(genX == 1){
            if(genY == 4){
                if(canStay[5][1] || canStay[4][2] || canStay[5][2]){
                    //cout << "HERE, " << canStay[1][5] << ", " <<canStay[2][4] << ", " <<canStay[2][5] << ", " << endl;
                    isCM = false;
                }
            } else if(genY == 5){
                if(canStay[4][1] || canStay[6][1] || canStay[5][2])
                    isCM = false;
            } else if(genY == 6){
                if(canStay[5][1] || canStay[6][2])
                    isCM = false;
            }
        } else if(genX == 2){
            if(genY == 4){
                if(canStay[5][1] || canStay[5][2] || canStay[4][3])
                    isCM = false;
            } else if(genY == 5){
                if(canStay[4][1] || canStay[5][1] || canStay[6][2] || canStay[4][2] || canStay[6][2] || canStay[4][3] || canStay[5][3] || canStay[6][3])
                    isCM = false;
            } else if(genY == 6){
                if(canStay[6][1] || canStay[6][3] || canStay[5][2]);
                    isCM = false;
            }
        } else if(genX == 3){
            if(genY == 4){
                if(canStay[5][3] || canStay[4][2] || canStay[5][2])
                    isCM = false;
            } else if(genY == 5){
                if(canStay[4][3] || canStay[6][3] || canStay[5][2])
                    isCM = false;
            } else if(genY == 6){
                if(canStay[6][2] || canStay[5][2] || canStay[5][3]){
                    //cout << "HERE, " << canStay[6][2] << ", " <<canStay[5][2] << ", " <<canStay[5][3] << ", " << endl;
                    isCM = false;
                }
                    //isCM = false;
            }
        }


        //bool isCM = true
        /*
        cout << endl;
        for(int i = 1; i <= 10; i++){
            for(int j = 1; j <= 10; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i = 1; i <= 10; i++){
            for(int j = 1; j <= 10; j++){
                cout << canStay[i][j] << " ";
            }
            cout << endl;
        }
        */

        if(isCM)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}
