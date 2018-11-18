#include <iostream>
using namespace std;

bool isRep[5000 + 1];

void setRep(){
    for(int i = 0 ; i < 10; i++){
        isRep[i] = true;
    }

    for(int i = 10 ; i < 100; i++){
        isRep[i] = (i % 11 != 0);
    }

    for(int i = 100 ; i < 1000; i++){
        int d = i % 10;
        int t = ((i - d) / 10) % 10;
        int h = ((((i - d) / 10) - t)/10);
        isRep[i] = (d != t && d != h && h != t);
    }

    for(int i = 1000; i < 5001; i++){
        int d = i % 10;
        int t = ((i - d) / 10) % 10;
        int h = ((((i - d) / 10) - t)/10) % 10;
        int th = ((((i - d) / 10) - t)/10 - h)/10;
        isRep[i] = (d != t && d != h && d != th && t != h && t != th && h != th);
    }
}
int M, N, ans;

int main(){
    setRep();
    while(cin >> M >> N){
        ans = 0;
        for(int i = M; i <= N; i++){
            //printf("%d: %d\n", i, isRep[i]);
            ans += isRep[i];
        }
        printf("%d\n", ans);
    }
}
