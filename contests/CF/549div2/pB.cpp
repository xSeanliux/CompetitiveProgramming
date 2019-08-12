#include <iostream>
using namespace std;

long long int N;

int getProd(int x){
    int res = 1;
    while(x){
        res *= x % 10;
        x /= 10;
    }
    return res;
}

int main(){
    cin >> N;

}
