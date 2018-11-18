#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

double shapes[100000 + 6][2];

bool comp(double s1[2], double s2[2]){
    return s1[0] < s2[0];
}

double getm(int i1, int i2){
    if(shapes[i2][0] > s1[0]) swap(s1, s2);
    if(shapes[i1][1] - shapes[i2][1] == 0) return -1;
    double res = (shapes[i1][0] - shapes[i2][0])/(s1[1] - shapes[i2][1]);
    if(res == 0){
        if (i2 == head -1) return -2;
        return getm(i1, i2 + 1);
    }
    return res;
}



double x[5], y[5];
double n, t, a, b, c, head = 0;
bool isGood;

bool alreadyExists(double x, double y){
    for(int i = 0 ; i < head; i++){
        if(shapes[i][0] == x && shapes[i][1] == y) return true;
    }
    return false;
}

double getm(int i1, int i2){
    double s2[2] = shapes[i2];
    double s1[2] = shapes[i1];
    if(s2[0] > s1[0]) swap(s1, s2);
    if(s1[1] - s2[1] == 0) return -1;
    double res = (s1[0] - s2[0])/(s1[1] - s2[1]);
    if(res == 0){
        if(i2 == head-1){
            return -2;
        } else {
            return getm(i1, i2+1);
        }
    }
    return res;
}

int main(){
    cin >> n;
    head = 0;
    for(int k = 0; k < n; k++){
        cin >> t;
        isGood = true;
        if(!t){ //is a circle
            //cout << "C" << endl;
            cin >> a >> b >> c; //r, x, y;
            if(!alreadyExists(b, c)){
                shapes[(int)head][0] = (x[0] + x[2])/(2+0.0);
                shapes[(int)head][1] = (y[0] + y[2])/(2+0.0);
                //cout << "Center: " <<
                head++;
            }
            shapes[(int)head][0] = b;
            shapes[(int)head][1] = c;
            head++;
        } else {
            double xS = 0, yS = 0;
            for(int i = 0 ; i < 4; i++){
                cin >> x[i] >> y[i];
                xS += x[i];
                yS += y[i];
            }
            double nX = xS/4;
            double nY = yS/4;
            if(!alreadyExists(nX, nY)){
                shapes[(int)head][0] = nX;
                shapes[(int)head][1] = nY;
                //cout << "Center: " <<
                head++;
            }

        }
    }
    isGood = true;
    if(n > 2){
        double m = getm(shapes[1], shapes[0]);
        //cout << m << endl;
        if(m == -2){
            break;
        }
        for(int i = 1 ; i < head; i++){
            if(getm(shapes[i], shapes[i-1]) != m){
                isGood = false;
                break;
            }
        }
    }

    if(isGood){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
