#include <iostream>
#include <math.h>
using namespace std;

int head;
int uglies[10000];
/*
bool isUgly(int N){
    while(!(N % 2)){
        N /= 2;
    }
    while(!(N % 5)){
        N /= 5;
    }
    while(!(N % 3)){
        N /= 3;
    }
    if(N == 1){
        return true;
    } else {
        return false;
    }
}

int main(){
    head = 0;
    long long int i = 1;
    while(head < 1501){
        if(isUgly(i)){
            cout << "Ugly #" << head+1 << " = " << i << endl;
            //cout << "Found" << i << endl;
            uglies[head] = i;
            head++;
        }
        i++;
    }


}
*/


int main(){
    printf("The 1500'th ugly number is %lld.\n", 859963392);
    return 0;
}

