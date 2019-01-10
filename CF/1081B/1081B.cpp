#include <iostream>
#define MAX 100000
using namespace std;

int N, arr[MAX + 5], assi[MAX + 5], occ[MAX + 5];
bool canDo = true;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        occ[i] = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        occ[arr[i]]++;
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(occ[i] != 0){
            if(occ[i] != N - i){
                canDo = false;
                break;
            } else {
                assi[i] = ++cnt;
            }
        }
    }
    if(canDo){
        printf("Possible\n");
        printf("%d", assi[arr[0]]);
        for(int i = 1; i < N; i++){
            printf(" %d", assi[arr[i]]);
        }
        printf("\n");
    } else {
        printf("Impossible\n");
    }

}
