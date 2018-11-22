#include <iostream>
using namespace std;
int reverseNum(int x){
    int k;
    while(x != 0){
        k += x % 10;
        x /= 10;
        k *= 10;
    }
    return k/10;
}
int main(){
    int N, counter;
    int k;
    while(cin >> N){
        k = 0;
        while(N != 0){
            k += (N % 2)+1;
            N /= 2;
            k *= 10;


        }

        cout << reverseNum(k/10) << endl;
    }

}
