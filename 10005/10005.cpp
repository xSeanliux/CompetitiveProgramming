#include <iostream>
#include <algorithm>

using namespace std;

struct Point{
    long long int x, y;
} points[105];

long long int N;
double R;

long long int distSquare(int i , int j){
    return ( points[i].x - points[j].x )  * ( points[i].x - points[j].x ) + ( points[i].y - points[j].y )  * ( points[i].y - points[j].y );
}

int main(){
    while(cin >> N){
        if(!N)
            return 0;

        for(int i = 0 ; i < N; i++){
            cin >> points[i].x >> points[i].y;
        }
        cin >> R;
        long long int maxDist = 0;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                maxDist = max(maxDist, distSquare(i, j));
            }
        }

        if(4 * R * R >= maxDist){
            cout << "The polygon can be packed in the circle." << endl;
        } else {
            cout << "There is no way of packing that polygon." << endl;
        }
    }
}
