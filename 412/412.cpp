#include <iostream>
#include <math.h>
using namespace std;

int N;
int arr[100];

int gcd(int a, int b){
    if(a % b == 0){
        return b;
    } else {
        return gcd(b, a%b);
    }
}

int main(){
    while(cin >> N){
        if(!N) return 0;
        int pairs = 0;
        for(int i = 0; i < N; i++) cin >> arr[i];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i == j) continue;
                if(gcd(arr[i], arr[j]) == 1) pairs++;
            }
        }
        if(!pairs){
            printf("No estimate for this data set.\n");
        } else {
            //cout << (N)*(N-1) << " total pairs " << pairs << " gcd pairs" << endl;
            double pi = sqrt((6.0*(N)*(N-1))/pairs);
            pi *= 1000*1000;
            round(pi);
            pi /= 1000*1000;
            printf("%f\n", pi);
        }
        // 6 : pi^2 = pairs  : (N)*(N-1)
        // pi^2 *  pairs = (N)*(N-1)*3
        //pi = sqrt(
    }
}
