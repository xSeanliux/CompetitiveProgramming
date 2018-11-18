#include <iostream>
using namespace std;

long long int m[1000], f[1000], N;

void runDP(){
    f[0] = 1;
    m[0] = 0;
    for(int i = 1; i <= 100; i++){
        f[i] = m[i-1] + 1;
        m[i] = f[i-1] + m[i-1];
    }
}

int main(){
    runDP();
    while(cin >> N){
        if(N < 0) return 0;
        cout << m[N] << " " << f[N] + m[N] << endl;
    }
}
