#include <iostream>
using namespace std;
char map[102][102]; //max 100
bool visited[102][102];
void run(int y, int x, int len){
    //cout << "Running x: " << x << ", y: " << y << endl;
    int minecount = 0;
    if(y < 0 | x < 0 | y >= len | x >= len | map[y][x] == '*' | visited[y][x]){
        return;
    } else {
        cout << "Running x: " << x << ", y: " << y << endl;
        for(int i = y-1; i <= y+2; i++){
            for(int j = x-1; j <= x+2; j++){
                if(i != y && j != x && !(i < 0 | j < 0 | i >= len | j >= len)){
                    cout << "Hi" << endl;
                    if(map[i][j] == '*'){
                        cout << "Found Mine" << endl;
                        minecount++;
                    }
                }
            }
        }
        visited[y][x] = true;
        if(minecount == 0){
           map[y][x] = '-';
        } else {
            map[y][x] = minecount - 'A';
        }
        cout << minecount << endl;


    }
    run(y+1, x, len);

    run(y, x+1, len);
    run(y-1, x, len);
    run(y, x-1, len);
}


int main(){
    int N;
    while(cin >> N){

        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < N; j++){
                cin >> map[i][j];
            }
        }
        run(0, 0, N);
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < N; j++){
                cout << map[i][j];
            }
            cout << endl;
        }
        cout << "Finished running" << endl;
    }


}
