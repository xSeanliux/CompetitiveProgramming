#include <iostream>
#include <math.h>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Vector {
    int a;
    int b;
};

Point points[50 + 10];
int nP, c = 0;
bool isConvex;
float sign;

float cross(Vector v1, Vector v2){
    return v1.a*v2.b - v2.a*v1.b;
}

float vA(Vector v){
    return sqrt(v.a*v.a + v.b*v.b);
}

double vSin(Vector v1, Vector v2){
    return cross(v1, v2)/(vA(v1) * vA(v2));
}

Vector newVector(Point *p1, Point *p2){
    Vector v;
    v.a = p2 -> x - p1 -> x;
    v.b = p2 -> y - p1 -> y;
    return v;
}

int main(){
    while(cin >> nP){
        if(!c){
            c++;
        } else {
            printf("\n");
        }
        if(!nP) return 0;
        isConvex = true;
        for(int i = 0 ; i < nP; i++){
            cin >> points[i].x >> points[i].y;
            //printf("points[%d]: x = %d, y = %d\n", i, points[i].x, points[i].x);
        }
        points[nP].x = points[0].x;
        points[nP].y = points[0].y;
        points[nP + 1].x = points[1].x;
        points[nP + 1].y = points[1].y;
        Vector v1 = newVector(&points[0], &points[1]);
        Vector v2 = newVector(&points[1], &points[2]);
        //printf("v1: %d, %d\n", v1.a, v1.b);
        //printf("v2: %d, %d\n", v2.a, v2.b);
        if(vSin(v1, v2) > 0) sign = 1;
        else sign = -1;
        //cout << "Sign = " << sign << endl;
        for(int i = 2; i <= nP; i++){
            v1 = newVector(&points[i-1], &points[i]);
            v2 = newVector(&points[i], &points[i+1]);
            if(sign * vSin(v1, v2) < 0){
                //printf("%d\n", i);
                //printf("v1: %d, %d\n", v1.a, v1.b);
                //printf("v2: %d, %d\n", v2.a, v2.b);
                //printf("Sin(v1, v2) = %f\n", vSin(v1, v2));
                isConvex = false;
                break;
            }
        }
        if(isConvex){
            printf("No");
        } else {
            printf("Yes");
        }
    }
}

