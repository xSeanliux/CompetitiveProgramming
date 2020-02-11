#include <iostream>
#include <math.h>
#define int long long int
using namespace std;

int vals[1005][1005], n, t;

inline int f(double d){
    return (int)(round(sqrt(d)));
}

inline int get(int x){
    if(x == 0){
        return f(vals[0][1] * vals[0][2] / vals[1][2]);
    } else if(x == 1){
        return f(vals[1][0] * vals[1][2] / vals[0][2]);
    }
    return f(vals[x][0] * vals[x][1] / vals[0][1]);
}


signed main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int g = 0;
        for(int j = 0; j < n; j++){
            cin >> vals[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        cout << get(i) << " ";
    }
}
