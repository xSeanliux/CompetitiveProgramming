#include <iostream>
#include <math.h>
#include <vector>
#define N 100
using namespace std;

int n, m, k, a, b;
long double arr[N][N], aug[N];


long double det(long double (&arr)[N][N]){
    long double d = 1;
    for(int i = 0; i < n - 1; i++){
        for(int k = i + 1; k < n; k++){
            if(fabs(arr[i][i]) < fabs(arr[k][i])) {
                swap(arr[i], arr[k]);
                swap(aug[i], aug[k]);
            }
        }
        if(!arr[i][i]) return 0;
    }

    for(int i = 0; i < n - 1; i++){
        if(!arr[i][i]) return 0;
        for(int k = i + 1; k < n; k++){
            long double factor = arr[k][i] / arr[i][i];
            for(int j = i; j < n; j++){
                arr[k][j] = arr[k][j] - factor * arr[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++) d *= arr[i][i];
    if(d < 1e-9) d = -d;
    return d;
}




int main(){
    while(cin >> n >> m >> k){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) arr[i][j] = n-1;
                else arr[i][j] = -1;
            }
        }
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            a--; b--;
            if(arr[a][b] == -1){ //beware fucking repeated edges
                arr[a][b] = 0; arr[b][a] = 0;
                arr[a][a]--;
                arr[b][b]--;
            }
        }
        long double new_arr[N][N];
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-1; j++){
                new_arr[i][j] = arr[i+1][j+1];
            }
        }
        n--;
        printf("%.0Lf\n", det(new_arr));
    }


}
