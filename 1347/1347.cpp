#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct Point{
    double x;
    double y;
};

Point points[1000 + 5];
double dpres[1000 + 5][1000 + 5];
int pN, p1, p2;

double dist(Point a, Point b){
    return(sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2)));
}

double dp(int i, int j){
    //cout << "Running dp(" << i << ", " << j << ")" << endl;
    if(i == pN-2) return dist(points[i], points[pN-1]) + dist(points[j], points[pN-1]);
    else if(dpres[i][j] != -1) {
            //cout << "Fast boi" << endl;
            return dpres[i][j];
    }
    else {
            double res =min((dist(points[i], points[i+1]) + dp(i+1, j)), dist(points[i+1], points[j]) + dp(i+1, i));
            dpres[i][j] = res;
            //cout << "in the bank " << i << ", " << j << endl;
            return res;
        }
}
int main(){
    while(cin >> pN){
        for(int i = 0 ; i < pN; i++){
            cin >> points[i].x >> points[i].y;
        }
        for(int  j = 0; j < 1005; j++)
        {
            for(int i = 0; i < 1005; i++)
            {
                dpres[i][j] = -1;
            }
        }
        //cout << dpres[0][0] << endl;
        double res = dp(0, 0);

        res *= 100;
        round(res);
        res /= 100;
        printf("%.2f\n", res);
    }
}
