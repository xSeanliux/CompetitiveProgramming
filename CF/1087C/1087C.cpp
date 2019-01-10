#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct Point{
    int x, y;
};

bool cmpX(const Point a, const Point b){
    return a.x < b.x;
}

bool cmpY(const Point a, const Point b){
    return a.y < b.y;
}

Point sortByX[3], sortByY[3];

int main(){
    for(int i = 0; i < 3; i++){
        cin >> sortByX[i].x >> sortByX[i].y;
        sortByY[i].x = sortByX[i].x;
        sortByY[i].y = sortByX[i].y;
    }
    sort(sortByX, sortByX + 3, cmpX);
    sort(sortByY, sortByY + 3, cmpY);

    int vertAns = 0, horAns = 0;
    //try vertial stem
    vertAns = sortByY[2].y - sortByY[0].y + 1;
    for(int i = 0; i < 3; i++){
        vertAns += abs(sortByX[i].x - sortByX[1].x);
    }
    horAns = sortByX[2].x - sortByX[0].x + 1;
    for(int i = 0; i < 3; i++){
        horAns += abs(sortByY[i].y - sortByY[1].y);
    }
    if(vertAns <= horAns){
        cout << vertAns << endl;
        for(int i = sortByY[0].y; i <= sortByY[2].y; i++){
            cout << sortByX[1].x << " " << i << endl;
        }
        for(int i = sortByX[0].x; i < sortByX[1].x; i++){
            cout << i << " " << sortByX[0].y << endl;
        }
        for(int i = sortByX[2].x; i > sortByX[1].x; i--){
            cout << i << " " << sortByX[2].y << endl;
        }
    } else {
        cout << horAns << endl;
        for(int i = sortByX[0].x; i <= sortByX[2].x; i++){
            cout << i << " " << sortByY[1].y << endl;
        }
        for(int i = sortByY[0].y; i < sortByY[1].y; i++){
            cout << sortByY[0].x << " " << i << endl;
        }
        for(int i = sortByY[2].y; i > sortByY[1].y; i--){
            cout << sortByY[2].x << " " << i << endl;
        }
    }
}
