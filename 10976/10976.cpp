#include <iostream>
using namespace std;

long long int n, a, b, c, head;
int sols[1000000][2];
int main(){
    while(cin >> n){
        c = 0;
        head = 0;
        long long int sq = n * n;
        for(long long int i = 1; i <= n ; i++){
            if(!(sq % i)){
                a = n + i;
                b = n + sq/i;
                sols[head][0] = a;
                sols[head][1] = b;
                c++;
                head++;
            }
        }
        printf("%d\n", c);
        for(int i =  0; i < head;i++){
            printf("1/%d = 1/%d + 1/%d\n", n, sols[i][1], sols[i][0]);
        }

    }
}

