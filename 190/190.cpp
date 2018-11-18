#include <iostream>
#include <math.h>
using namespace std;

struct Point{
    double x;
    double y;
} points[4];

bool c = false;

int main(){
    while(cin >> points[1].x >> points[1].y){
        for(int i = 2; i <= 3; i++)
            cin >> points[i].x >> points[i].y;
        Point centre;
        double A1 = (points[2].x - points[1].x);
        double B1 = (points[2].y - points[1].y);
        double C1 = (points[2].x*points[2].x - points[1].x*points[1].x + points[2].y*points[2].y - points[1].y*points[1].y)/2;
        double A2 = (points[3].x - points[2].x);
        double B2 = (points[3].y - points[2].y);
        double C2 = (points[3].x*points[3].x - points[2].x*points[2].x + points[3].y*points[3].y - points[2].y*points[2].y)/2;
        //let the center be at (x, y)
        //then A1*x + B1*y = C1
        //     A2*x + B2*y = C2
        centre.y = (C1*A2 - C2*A1)/(B1*A2-B2*A1);
        centre.x = (C1*B2 - C2*B1)/(A1*B2-A2*B1);
        double R = sqrt((points[1].x - centre.x)*(points[1].x - centre.x) + (points[1].y - centre.y)*(points[1].y - centre.y));
        if(centre.x < 0){
            printf("(x + %.3f)^2", -centre.x);
        } else if(centre.x == 0){
            printf("x^2");
        } else {
            printf("(x - %.3f)^2", centre.x);
        }
        printf(" + ");
        if(centre.y < 0){
            printf("(y + %.3f)^2", -centre.y);
        } else if(centre.y == 0){
            printf("y^2");
        } else {
            printf("(y - %.3f)^2", centre.y);
        }
        printf(" = %.3f^2\nx^2 + y^2", R);
        if(centre.x > 0){
            printf(" - %.3fx", 2*centre.x);
        } else if(centre.x < 0){
            printf(" + %.3fx", -2*centre.x);
        }
        if(centre.y > 0){
            printf(" - %.3fy", 2*centre.y);
        } else if(centre.y < 0){
            printf(" + %.3fy", -2*centre.y);
        }
        if(centre.x*centre.x + centre.y*centre.y - R*R > 0){
            printf(" + %.3f", centre.x*centre.x + centre.y*centre.y - R*R);
        } else if(centre.x*centre.x + centre.y*centre.y - R*R < 0){
            printf(" - %.3f", -(centre.x*centre.x + centre.y*centre.y - R*R));
        }
        printf(" = 0\n\n");
    }
}
