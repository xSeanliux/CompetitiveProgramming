#include <iostream>
using namespace std;


int arr[15][15];
int N;


int sumSquare(int a, int b){
    if(a > b) return 0;
    int sum = 0;
    for(int i = a; i <= b; i++){
        for(int j = a; j <= b; j++){
            sum += arr[i][j];
        }
    }
    return sum;
}
int c;
int main(){
    c = 1;
    while(cin >> N){
        if(N == 0) return 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
            }
        }
        int sum = 0;
        int u = N-1, l = 0;
        cout << "Case " << c << ":";
        while(u - l > -1){
            cout << " " << sumSquare(l, u) - sumSquare(l+1, u-1);
            u--;
            l++;
        }
        cout << endl;
        c++;
    }

}
