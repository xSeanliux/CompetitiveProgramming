
#include <iostream>
using namespace std;


void Report(int x1,int y1,int x2,int y2,int x3,int y3){
    cout << "(" << x1 << ", " << y1 << ")" << endl;
    cout << "(" << x2 << ", " << y2 << ")" << endl;
    cout << "(" << x3 << ", " << y3 << ")" << endl;
    cout << "--------------------" << endl;
    return;
}

long long int Counter = 0;

int ans[3][2], cnt = 0;
void get(int ulx, int uly, int sz, int holeAtx, int holeAty){
    //if(holeAty - uly > 2 || holeAty - uly < -2 || holeAtx - ulx > 2 || holeAtx - ulx < -2) return;
    //cout << "Top: (" << ulx << ", " << uly << "), sz = " << sz << ", Hole: (" << holeAtx << ", " << holeAty << ")" << endl;
    if(sz == 2){
        cnt = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(!(ulx + i == holeAtx && uly + j == holeAty)){
                    ans[cnt][0] = ulx + i;
                    ans[cnt][1] = uly + j;
                    cnt++;
                }
            }
        }
        Report(ans[0][1], ans[0][0], ans[1][1], ans[1][0], ans[2][1], ans[2][0]);
        Counter++;
        return;
    } else {
        if(holeAtx >= ulx + sz/2 && holeAty >= uly + sz/2){ //Hole at DR
            //cout << "DR" << endl;
            //Report(uly + sz/2 - 1, ulx + sz/2 - 1,  uly + sz/2 - 1, ulx + sz/2, uly + sz/2, ulx + sz/2 - 1);
            Counter++;
            Report(ulx + sz/2 - 1, uly + sz/2 - 1, ulx + sz/2, uly + sz/2 - 1, ulx + sz/2 - 1, uly + sz/2);
            get(ulx, uly, sz/2, ulx + sz/2 - 1, uly + sz/2 - 1); //UL
            get(ulx + sz/2, uly, sz/2, ulx + sz/2, uly + sz/2 - 1); //UR
            get(ulx, uly + sz/2, sz/2, ulx + sz/2 - 1, uly + sz/2); //DL
            get(ulx + sz/2, uly + sz/2, sz/2, holeAtx, holeAty); //DR
        } else if(holeAtx >= ulx + sz/2 && holeAty < uly + sz/2){ //Hole at UR
            //cout << "UR" << endl;
            Report(ulx + sz/2 - 1, uly + sz/2 - 1, ulx + sz/2, uly + sz/2, ulx + sz/2 - 1, uly + sz/2);
            //Report(uly + sz/2 - 1, ulx + sz/2 - 1, uly + sz/2, ulx + sz/2, uly + sz/2, ulx + sz/2 - 1);
            Counter++;
            get(ulx, uly, sz/2, ulx + sz/2 - 1, uly + sz/2 - 1); //UL
            get(ulx + sz/2, uly, sz/2, holeAtx, holeAty); //UR
            get(ulx, uly + sz/2, sz/2, ulx + sz/2 - 1, uly + sz/2); //DL
            get(ulx + sz/2, uly + sz/2, sz/2, ulx + sz/2, uly + sz/2); //DR
        } else if(holeAtx < ulx + sz/2 && holeAty >= uly + sz/2){ //Hole at DL
            //cout << "DL" << endl;
            Report(ulx + sz/2 - 1, uly + sz/2 - 1, ulx + sz/2, uly + sz/2 - 1, ulx + sz/2, uly + sz/2);
            //Report(uly + sz/2 - 1, ulx + sz/2 - 1, uly + sz/2 - 1, ulx + sz/2, uly + sz/2, ulx + sz/2);
            Counter++;
            get(ulx, uly, sz/2, ulx + sz/2 - 1, uly + sz/2 - 1); //UL
            get(ulx + sz/2, uly, sz/2, ulx + sz/2, uly + sz/2 - 1); //UR
            get(ulx, uly + sz/2, sz/2, holeAtx, holeAty); //DL
            get(ulx + sz/2, uly + sz/2, sz/2, ulx + sz/2, uly + sz/2); //DR
        } else { //Hole at UL
            //cout << "UL" << endl;
            Report(ulx + sz/2, uly + sz/2 - 1, ulx + sz/2, uly + sz/2, ulx + sz/2 - 1, uly + sz/2);
            //Report(uly + sz/2 - 1, ulx + sz/2, uly + sz/2, ulx + sz/2, uly + sz/2, ulx + sz/2 - 1);
            Counter++;
            get(ulx, uly, sz/2, holeAtx, holeAty); //UL
            get(ulx + sz/2, uly, sz/2, ulx + sz/2, uly + sz/2 - 1); //UR
            get(ulx, uly + sz/2, sz/2, ulx + sz/2 - 1, uly + sz/2); //DL
            get(ulx + sz/2, uly + sz/2, sz/2, ulx + sz/2, uly + sz/2); //DR
        }
        return;
    }
}

void solve(int N, int X, int Y){
    Counter = 0;
    get(1, 1, N, Y, X);
    //cout << "CNT: " << Counter << endl;
}

int main(){
    solve(4, 1, 1);
}



