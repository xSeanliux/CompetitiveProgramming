#include <iostream>
using namespace std;

int ans[8][2]; //stores nine coordinates


bool isValid(int y, int x){

    for(int i = 0; i < 8; i++){
        if(ans[i][0] == y && ans[i][1] == x){
            return false;
        }
    }

    cout << "x: " << x << " y: " << y << endl;
    if(x > 8 | x < 1 | y > 8 | y | 1) return  false;
    for(int i = 1 ; i <= 8 ; i ++){
            if(ans[i][0] == y | ans[i][1] == x) return false;
            for(int j = 1 ; j <= 8; j++){
                if(ans[i][0] + j == y & ans[i][1] + j == x) return false; //the diagonal ones #1 -> down-right
                else if (ans[i][0] + j == y & ans[i][1] - j == x) return false; //the diagonal ones #2 -> down-left
                else if(ans[i][0] - j == y & ans[i][1] + j == x) return false; //the diagonal ones #3 -> up-right
                else if(ans[i][0] - j == y & ans[i][1] - j == x) return false; //the diagonal ones #4 -> up-left
            }

    }
    return true;

}


void dfs(int x, int y, int iteration){
    cout << "Iteration: " << iteration << endl;
    if(iteration = 8){
        for(int i = 0 ; i < 8; i++){
            cout << ans[i][1] << ", " << ans[i][0] << endl;
        }
    }

    for(int i = -8 ; i <= 8 ; i++){
        for(int j = -8 ;j <= 8 ; j++){
                if(isValid(y+i, x+j)){
                        dfs(y+i, x+j, iteration+1);

                }

        }
    }










}









//void run(int x, int iteration){
    /*
cout << "Iteration: " << iteration << endl;
    if(iteration >= 9){

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 2; j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return;

    } else {
        run(y+1, x+1, iteration+1);
        run(y+1, x, iteration+1);
        run(y+1, x-1, iteration+1);
        run(y, x+1, iteration+1);
        run(y, x-1, iteration+1);
        run(y-1, x+1, iteration+1);
        run(y-1, x, iteration+1);
        run(y-1, x-1, iteration+1);
        if(x > 8 | x < 1 | y > 8 | y < 1) return;
        for(int i = 0 ; i <= 8 ; i ++){

            if(ans[i][0] == y | ans[i][1] == x) return;
            for(int j = 1; j < 8 ; j++){


                if(ans[i][0] + j == y & ans[i][1] + j == x) return; //the diagonal ones #1 -> down-right
                else if (ans[i][0] + j == y & ans[i][1] - j == x) return; //the diagonal ones #2 -> down-left
                else if(ans[i][0] - j == y & ans[i][1] + j == x) return; //the diagonal ones #3 -> up-right
                else if(ans[i][0] - j == y & ans[i][1] - j == x) return; //the diagonal ones #4 -> up-left
            }
        }
        ans[iteration][0] = y;
        ans[iteration][1] = x;
    }
    */


//}


int main(){
    int N;
    int startx, starty;
    while(cin >> N){
        for(int i = 0 ; i < N; i++){
            cin >> startx >> starty;
            ans[0][0] = starty;
            ans[0][1] = startx;
            dfs(starty, startx, 0);
        }
    }

}
