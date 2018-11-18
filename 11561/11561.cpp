
#include <iostream>
using namespace std;
char Map[55][55];

int width, height, gold;


int dfs(int y, int x){
    if(y < 1 || x < 1 || x >= width-1 || y >= height-1 || Map[y][x] == '/'){
        return 0;
    } else if(Map[y][x] == '#'){
        return 0;
    } else {
        if(Map[y][x] == 'G'){
            gold++;
        }
    }


    Map[y][x] = '/';

    if(Map[y][x+1] == 'T' || Map[y][x-1] == 'T' || Map[y+1][x] == 'T' || Map[y-1][x] == 'T'){
        return 0;
    }
    dfs(y+1, x);
    dfs(y-1, x);
    dfs(y, x+1);
    dfs(y, x-1);


}

int main(){
    while(cin >> width >> height){
        int x, y;
        for(int i = 0 ; i < height ; i++){
            for(int j = 0; j < width; j++){
                cin >> Map[i][j];
                //cout << map[i][j];
                if(Map[i][j] == 'P'){
                    y = i;
                    x = j;
                }
            }
            //cout << endl;
        }

        gold = 0;
        dfs(y, x);
        //display();
        cout << gold << endl;

    }


}
