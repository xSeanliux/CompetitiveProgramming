#include <iostream>
using namespace std;

const int MAXN = 1e5, INF = 0x7FFFFFFF;
int n, m, a, b;

struct Car{
    int prev, next;
} cars[MAXN + 10];

int main(){
    scanf("%d%d", &n, &m);
    cars[0] = {-INF, 1};
    for(int i = 1; i <= n; i++){
        cars[i] = {i-1, i+1};
    }
    cars[n+1] = {n, INF};
    while(m--){
        scanf("%d%d", &a, &b);
        if(!a){ //b is attacked
            cars[cars[b].prev].next = cars[b].next;
            cars[cars[b].next].prev = cars[b].prev;
        } else { //b overtakes the next car

            int prevCar = cars[b].prev;
            if(!prevCar) continue;
            int p2Car = cars[prevCar].prev, nextCar = cars[b].next;
            cars[p2Car].next = b;
            cars[nextCar].prev = prevCar;
            cars[b].prev = p2Car;
            cars[b].next = prevCar;
            cars[prevCar].prev = b;
            cars[prevCar].next = nextCar;
        }
        int currentInd = cars[0].next;
    }
    int currentInd = cars[0].next;
    printf("%d", currentInd);
    currentInd = cars[currentInd].next;
    while(currentInd <= n){
        printf(" %d", currentInd);
        currentInd = cars[currentInd].next;
    }
    printf("\n");
}
