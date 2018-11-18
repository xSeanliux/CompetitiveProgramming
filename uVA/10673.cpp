#include <iostream>
#include <math.h>
using namespace std;

int x, k;

int main(){
    int p, q;
    int N;
    while(cin >> N){
        for(int i = 0; i < N; i++){
            cin >> x >> k;
            int z = floor(x/k);
            if(x % k == 0){ //easy case
                p = 0;
                q = k;
            } else if(x < k){ //special case
                p = 0;
                q = x;
            } else {
                for(int i = 1; i < x; i++){ //general case, use a search by brute force
                    if ((x-i)%z == 0){
                        int kk = (x-i)/z;
                        q = i;
                        p = kk - q;
                        break;
                    }
                }
            }
            cout << p << " " << q << endl;
        }
    }
}
