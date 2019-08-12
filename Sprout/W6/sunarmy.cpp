#include <iostream>
using namespace std;

int ans[(int)1e6 + 10];

void go(int y, int x, int h, int w){
    int maxVal = getVal(y + h/2, x), minAt = x;
    for(int i = 1; i < w; i++){
        if(maxVal < getVal(y + h/2, x + i)){
            minAt = x + i;
            minVal = getVal(y + h/2, x + i);
        }
    }
    ans[y] = minVal;
    go(y, x, h/2, )
}

void solve(int N, int M){
    go(1, 1, N, M);
}
