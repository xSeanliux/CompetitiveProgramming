#include <iostream>
#include <math.h>
using namespace std;

int N;
bool arr[160][160];
//radius
double dist(int x, int y){
    return sqrt(x*x + y*y);
}
int c = 1;
int main(){
    while(cin >> N){
        if(c != 1){
            cout << endl;
        } else {
            c++;
        }
        double rad = N-0.5;
        int a = 0, p = 0; //all, partial
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                if(dist(i, j) <= rad){
                    //cout << i<< ", " << j << " is int eh cricle" << endl;
                    arr[i][j] = true;
                } else {
                    arr[i][j] = false;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(arr[i][j] == 1){
                    p++;
                    if(arr[i+1][j+1] == 1 && arr[i][j] == 1){
                        //cout << i << ", " << j << endl;
                        p--;
                        a++;
                    }
                }

            }
        }

        printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n", N, p*4, a*4);
    }
}
