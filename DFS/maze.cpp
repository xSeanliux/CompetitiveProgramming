#include <iostream>
using namespace std;
int max_x, max_y;
char map[100][100]; //100x100 map should be big enough
bool visited[100][100]; //same reasoning as above
bool ans = false;
int minLen;
int currentRoute[1000][2];
int solutionRoute[1000][2];
void run(int y, int x, int currentLen)
{

    if( x < 0 || x >= max_x || y < 0 || y >= max_y || minLen <= currentLen)
        return;
    if( visited[y][x] || map[y][x] == 'x' )
        return;

    visited[y][x] = 1;
    currentRoute[currentLen][0] = y, currentRoute[currentLen][1] = x;
    if( map[y][x] == 'O' ){
        ans = true;
        if(currentLen < minLen){
            minLen = currentLen;
            for(int i = 0 ; i < 1000; i++){
                solutionRoute[i][0] = currentRoute[i][0];
                solutionRoute[i][1] = currentRoute[i][1];
            }
        }
        for(int i = 0; i < 1000; i++){
            currentRoute[i][0] = -1;
        }
    }


    run( y-1, x , currentLen+1);
    run( y+1, x , currentLen+1);
    run( y, x-1 , currentLen+1);
    run( y, x+1 , currentLen+1);

    visited[y][x] = 0;


}


int main()
{

    int start_x, start_y;
    while(cin >> max_x >> max_y)
    {

        //init map;
        for(int i = 0; i < max_y; i++)
        {
            for(int j = 0; j < max_x; j++)
            {
                cin >> map[i][j];
                visited[i][j] = false;
                if(map[i][j] == 'M')
                {
                    start_x = j;
                    start_y = i;
                }
            }
        }
        for(int i = 0; i < 1000; i++){
            solutionRoute[i][0] = -1;

        }
        ans = false;
        minLen = max_x*max_y;
        run(start_y, start_x, 0);
        cout << minLen << endl;
        for(int i = 0; i < 1000; i++){
            if(solutionRoute[i][0] != -1){
                map[solutionRoute[i][0]][solutionRoute[i][1]] = 'Y';
            }
        }
        for(int i = 0; i < max_y; i++)
        {
            for(int j = 0; j < max_x; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }


    }




}
