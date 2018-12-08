#include <iostream>
#include <math.h>
using namespace std;

int P;

int gcd(int a, int b){
    //cout << "Running " << a << ", " << b << endl;
    return (b == 0) ? a : gcd(b, a % b);
}

int main(){
    //uses pick's theorem and shoelace formula
    while(cin >> P){
        if(!P) return 0;
        long long int points[P + 1][2];
        for(int i = 0 ; i < P; i++){
            cin >> points[i][0] >> points[i][1];
        }
        points[P][0] = points[0][0];
        points[P][1] = points[0][1];
        long long int area = 0;
        for(int i = 0 ; i < P; i++){
            area += points[i][0] * points[i+1][1];
            area -= points[i][1] * points[i+1][0];
            //cout << "Area += " << points[i][0] * points[i+1][1] << endl;
            //cout << "Area -= " << points[i][1] * points[i+1][0] << endl;
        }
        area /= 2;
        if(area < 0) area = -area;
        long long int boundaries = 0;
        for(int i = 0 ; i < P; i++){
            /*
            For the line from (a,b) to (c,d) the number of such points is
                   gcd(delta x, delta y) + 1 (both ends including)
            */
            long long int pointCount = gcd(abs(points[i][0] - points[i+1][0]), abs(points[i][1] - points[i+1][1])) - 1;
            //printf("There are %d points between (%d, %d) and (%d, %d)\n", pointCount, points[i][0], points[i][1], points[i+1][0], points[i+ 1][1] );
            boundaries += pointCount;
        }
        boundaries += P;
        //cout << "A = " << area << ", points" << boundaries << endl;
        printf("%lld\n", area - boundaries/2 + 1 );
        // i = A + 1 - b/2 = (2A - b + 2)/2
    }
}
