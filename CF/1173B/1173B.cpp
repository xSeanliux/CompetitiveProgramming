#include <iostream>
using namespace std;

int N, cx = 1, cy = 1;

int f(int x){
    return (x % 2 ? (x + 1)/2 : x/2 + 1);
}

int main(){
    cin >> N;
    cout << f(N) << endl;
    for(int i = 1; i <= N; i++){
        cout << cx << " " << cy << endl;
        if(i % 2){
            cx++;
        } else {
            cy++;
        }
    }
}
