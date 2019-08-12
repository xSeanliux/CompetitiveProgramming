#include <iostream>
#include <math.h>
#include <vector>
#define N 10000
using namespace std;

int n;
double arr[N][N], aug[N];
vector<double> ans;

void elim(double (&arr)[N][N]){
    for(int i = 0; i < n - 1; i++){
        for(int k = i + 1; k < n; k++){
            if(fabs(arr[i][i]) < fabs(arr[k][i])) {
                swap(arr[i], arr[k]);
                swap(aug[i], aug[k]);
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        for(int k = i + 1; k < n; k++){
            double factor = arr[k][i] / arr[i][i];
            aug[k] -= aug[i] * factor;
            for(int j = i; j < n; j++){
                arr[k][j] -= arr[i][j] * factor;
            }
        }
    }
}

int main(){
    cin >> n;
    //assert(n <= 10);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
        //cin >> aug[i];
    }
    elim(arr);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) printf("%2.2lf  ", arr[i][j]);
        cout << endl;
    }
    int _arr[N]
}
