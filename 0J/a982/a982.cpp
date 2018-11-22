#include <iostream>
using namespace std;
bool canGo;
int ans;
char map[100+5][100+5];
int N;
int head, tail;

struct Point{
    int y;
    int x;
    int steps;
};
Point queue[100*100+5];


int main(){
    while(cin >> N){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N ; j++){
                cin >> map[i][j];
            }
        }
        int x = 1, y = 1; //from 1,1 to n-2, n-2

        canGo = false;
        head = tail = 0;
        int currentLen = 1;
        queue[tail].x = x, queue[tail].y = y, queue[tail].steps = currentLen;
        tail++;
        currentLen++;
        while(tail != head){
            currentLen = queue[head].steps;
            if(x > 0 && map[y][x-1] == '.'){
                queue[tail].x = x-1, queue[tail].y = y, queue[tail].steps = currentLen+1;
                tail++;
                map[y][x-1] = 'Y';
            }
            if(y > 0 && map[y-1][x] == '.'){
                queue[tail].x = x, queue[tail].y = y-1, queue[tail].steps = currentLen+1;
                tail++;
                map[y-1][x] = 'Y';
            }
            if(y < N && map[y+1][x] == '.'){
                queue[tail].x = x, queue[tail].y = y+1, queue[tail].steps = currentLen+1;
                tail++;
                map[y+1][x] = 'Y';
            }
            if(x < N && map[y][x+1] == '.'){
                queue[tail].x = x+1, queue[tail].y = y, queue[tail].steps = currentLen+1;
                tail++;
                map[y][x+1] = 'Y';
            }
            head++;
            x = queue[head].x;
            y = queue[head].y;




        }
        for(int i = 0; i < tail; i++){
            if(queue[i].x == N-2 && queue[i].y == N-2){
                canGo = true;
                cout << queue[i].steps;
                return 0;
            }
        }
        cout << "No solution!" << endl;
        return 0;
    }
}
