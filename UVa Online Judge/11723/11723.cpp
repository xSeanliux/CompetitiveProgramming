#include <iostream>
#include <math.h>
using namespace std;

int N, R, c = 0;

int main(){
    while(cin >> N >> R){
        if(!N && !R)
            return 0;
        if(27 * R < N){
            printf("Case %d: impossible\n", ++c);
        } else {
            int ans = ceil((N+0.0)/R) - 1;
            printf("Case %d: %d\n", ++c, ans);
        }
    }
}
