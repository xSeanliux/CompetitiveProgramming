#include <iostream>
using namespace std;

int a, b;
long long int squares[1000 + 5];

int main(){
    for(int i = 0; i < 1004; i++){
        squares[i] = i * i;
    }
    while(cin >> a >> b){
        if(!a && !b) return 0;
        int counter = 0;
        if(a > b) swap(a, b);
        for(int i = 0; i < 1004; i++){
            if(squares[i] > b){
                break;
            } else if(squares[i] >= a && squares[i] <= b){
                counter++;
            }
        }
        printf("%d\n", counter);
    }
}
