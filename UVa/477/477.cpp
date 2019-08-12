#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct Point{
    double x, y;
    Point(double x, double y): x(x), y(y)
        {}
    Point(){}
} p;

char c;
double a, b, r, d, e;
bool hasContain;

double dist(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

class Shape{
public:
    Point ul, dr, c;
    double r;
    bool type; //0 for circle,
    bool isIn(Point p){
        if(type){ //rect
            return (p.x < dr.x && p.x > ul.x && p.y < ul.y && p.y > dr.y);
        } else { //circle
            //printf("Radius: %f, dist: %f\n", dist(c, p), r);
            return dist(c, p) < r;
        }
    }
    Shape(double r, Point c): r(r), c(c), type(0)
        {
            //printf("New circle with rad %f, (x, y) = (%f, %f)\n", r, c.x, c.y);
        }
    Shape(Point ul, Point dr): ul(ul), dr(dr), type(1)
        {
            //printf("ul: (%f, %f), dr: (%f, %f)\n", ul.x, ul.y, dr.x, dr.y);
        }
};


int main(){
    vector<Shape> vec;
    while(scanf("%c", &c)){
        if(c == '*') break;
        else if(c == 'r'){
            scanf("%lf %lf %lf %lf", &a, &b, &d, &e);
            //printf("(%f %f), (%f %f)\n", a, b, d, e);
            vec.push_back(Shape(Point(a, b), Point(d, e)));
        } else if(c == 'c'){
            scanf("%lf %lf %lf", &a, &b, &r);
            //printf("(%f %f), %f", a, b, r);
            vec.push_back(Shape(r, Point(a, b)));
        }
    }
    int cp = 0;
    while(scanf("%lf %lf", &a, &b)){
        if(abs(a - 9999.9) < 0.00000001 && abs(b - 9999.9) < 0.00000001) return 0;
        hasContain = false;
        cp++;
        p = Point(a, b);
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].isIn(p)){
                printf("Point %d is contained in figure %d\n", cp, i+1);
                hasContain = true;
            }
        }
        if(!hasContain) printf("Point %d is not contained in any figure\n", cp);
    }
}
