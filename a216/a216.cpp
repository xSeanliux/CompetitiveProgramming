#include <iostream>
using namespace std;

long long int f(int N){
    if(N == 1) return 1;
    else return N + f(N-1);
}

long long int g(int N){
    if(N == 1) return 1;
    else return f(N) + g(N-1);
}

int main(){
    int N;
    while(cin >> N){
        cout << f(N) << " " << g(N) << endl;
    }
}
