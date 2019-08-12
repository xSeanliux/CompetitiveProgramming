#include <iostream>
using namespace std;


const int MAXN = 1e4;
unsigned long long int ways[MAXN + 10], cube, N;

int main(){
    for(int i = 0; i <= MAXN; i++) ways[i] = 0;
    ways[0] = 1;
    for(unsigned long long int i = 1; i*i*i <= MAXN; i++){
        cube = i * i * i;
        for(int j = cube; j <= MAXN; j++){
            ways[j] += ways[j - cube];
        }
    }
    while(cin >> N){
        cout << ways[N] << endl;
    }
}
