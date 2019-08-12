#include <iostream>
#include <math.h>
using namespace std;

int N, ansx, ansy;

int main(){
    while(cin >> N){
        if(!N) return 0;
        ansy = 2147483647;
        for(int i = 1; i*i*i <= N; i++){
            if(!(N % i)){
                double test_x = (3*i*i + sqrt(12*i*N - 3*i*i*i*i))/6/i;
                if(fabs((int)(test_x) - test_x <= 1e-6)){
                    int x = (int)(test_x);
                    int y = -(int)(3*i*i - sqrt(12*i*N - 3*i*i*i*i))/6/i;
                    if(x * x * x - y * y * y == N){
                        if(ansy > y){
                            ansy = y;
                            ansx = x;
                        }
                    }
                }
            }
        }
        if(ansy == 2147483647){
            cout << "No solution" << endl;
        } else {
            cout << ansx << " " << ansy << endl;
        }
    }
}
