
#include <vector>
#include <iostream>
#include <utility>
#define F first
#define S second
using namespace std;


vector<pair<int, int> > p;
int cnt = 0;
/*
void Report(int x1,int y1,int x2,int y2,int x3,int y3){
    cout << "(" << x1 << ", " << y1 << ")" << endl;
    cout << "(" << x2 << ", " << y2 << ")" << endl;
    cout << "(" << x3 << ", " << y3 << ")" << endl;
    cout << "--------------------" << endl;
    return;
}
*/

void get(int x, int y, int sz, int holeX, int holeY){
    if(sz == 2){
        p.clear();
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(!(x + i == holeX && y + j == holeY)){
                    p.push_back({x + i, y + j});
                }
            }
        }
        Report(p[0].F, p[0].S, p[1].F, p[1].S, p[2].F, p[2].S);
        return;
    }
    if(holeX >= x + sz/2 && holeY >= y + sz/2){ //Hole at DR
        Report(x + sz/2 - 1, y + sz/2 - 1, x + sz/2, y + sz/2 - 1, x + sz/2 - 1, y + sz/2);
        get(x, y, sz/2, x + sz/2 - 1, y + sz/2 - 1); //UL
        get(x + sz/2, y, sz/2, x + sz/2, y + sz/2 - 1); //UR
        get(x, y + sz/2, sz/2, x + sz/2 - 1, y + sz/2); //DL
        get(x + sz/2, y + sz/2, sz/2, holeX, holeY); //DR
    } else if(holeX < x + sz/2 && holeY >= y + sz/2){ //Hole at DL
        Report(x + sz/2 - 1, y + sz/2 - 1, x + sz/2, y + sz/2 - 1, x + sz/2, y + sz/2);
        get(x, y, sz/2, x + sz/2 - 1, y + sz/2 - 1); //UL
        get(x + sz/2, y, sz/2, x + sz/2, y + sz/2 - 1); //UR
        get(x, y + sz/2, sz/2, holeX, holeY); //DL
        get(x + sz/2, y + sz/2, sz/2, x + sz/2, y + sz/2); //DR
    } else if(holeX >= x + sz/2 && holeY < y + sz/2){ //Hole at UR
        Report(x + sz/2 - 1, y + sz/2 - 1, x + sz/2 - 1, y + sz/2, x + sz/2, y + sz/2);
        get(x, y, sz/2, x + sz/2 - 1, y + sz/2 - 1); //UL
        get(x + sz/2, y, sz/2, holeX, holeY); //UR
        get(x, y + sz/2, sz/2, x + sz/2 - 1, y + sz/2); //DL
        get(x + sz/2, y + sz/2, sz/2, x + sz/2, y + sz/2);  //DR
    } else { //Hole at UL
        Report(x + sz/2, y + sz/2 - 1, x + sz/2, y + sz/2, x + sz/2 - 1, y + sz/2);
        get(x, y, sz/2, holeX, holeY); //UL
        get(x + sz/2, y, sz/2, x + sz/2, y + sz/2 - 1); //UR
        get(x, y + sz/2, sz/2, x + sz/2 - 1, y + sz/2); //DL
        get(x + sz/2, y + sz/2, sz/2, x + sz/2, y + sz/2);  //DR
    }
}

void solve(int N, int X, int Y){
    get(1, 1, N, X, Y);
}
/*
int main(){
    solve(4, 1, 1);
}
*/

