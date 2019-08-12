#include <iostream>
using namespace std;

bool check(int n1, int n2, int n3){
    bool hasChar[10];
    for(int i = 0; i < 10; i++) hasChar[i] = false;
    hasChar[0] = true;
    int t;
    for(int i = 0; i < 3; i++){
        t = n1 % 10;
        if(hasChar[t]) return false;
        hasChar[t] = true;
        n1 /= 10;
    }
    for(int i = 0; i < 3; i++){
        t = n2 % 10;
        if(hasChar[t]) return false;
        hasChar[t] = true;
        n2 /= 10;
    }

    for(int i = 0; i < 3; i++){
        t = n3 % 10;
        if(hasChar[t]) return false;
        hasChar[t] = true;
        n3 /= 10;
    }
    return true;
}

int main(){
    for(int i = 0; i <= 1000; i++){
        if(check(i, 2*i, 3*i)){
            printf("%d %d %d\n", i, 2*i, 3*i);
        }
    }
    //ans:
    /*
    192 384 576
    219 438 657
    273 546 819
    327 654 981
    */
}
