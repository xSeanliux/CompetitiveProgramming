#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Point{
    double x, y;
    Point(double x, double y): x(x), y(y){}

};

struct Rect{
    double lx, ly, rx, ry;
    bool isIn(Point p){
        return((p.x < rx && p.x > lx) && (p.y > ry && p.y < ly));
    }
    Rect(double _lx, double _ly, double _rx, double _ry): lx(_lx), ly(_ly), rx(_rx), ry(_ry){}
};

char c;
double lx, ly, rx, ry, x, y;
int pc = 0, inC;
vector<Rect> vec;
int main(){
     while(cin >> c){
        if(c == '*') break;
        cin >> lx >> ly >> rx >> ry;
        vec.push_back(Rect(lx, ly, rx, ry));
     }
     while(cin >> x >> y){
        if((fabs(x - 9999.9) < 1e-9) && (fabs(y - 9999.9) < 1e-9)) return 0;
        ++pc;
        inC = 0;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].isIn(Point(x, y))){
                printf("Point %d is contained in figure %d\n", pc, i + 1);
                inC++;
            }
        }
        if(!inC) printf("Point %d is not contained in any figure\n", pc);
     }
}
