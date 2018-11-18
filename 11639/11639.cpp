#include <iostream>
using namespace std;

int c;
struct Rect{
    int x1, y1;
    int x2, y2;
};

Rect r1, r2;

int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
        cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
        if(r1.x1 > r2.x1) swap(r1, r2);
        if(r1.)
    }
}
