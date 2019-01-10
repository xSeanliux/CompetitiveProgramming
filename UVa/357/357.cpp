#include <iostream>
using namespace std;

double ways[30000 + 5];
int MAXLEN = 30000;
int main(){
    for(int i = 0; i <= 30000; i++){
        ways[i] = 1;
    }



    for(int i = 5; i <= MAXLEN; i++){
        ways[i] += ways[i-5];
    }

    for(int i = 10; i <= MAXLEN; i++){
        ways[i] += ways[i-10];
    }

    for(int i = 25; i <= MAXLEN; i++){
        ways[i] += ways[i-25];
    }


    for(int i = 50; i <= MAXLEN; i++){
        ways[i] += ways[i-50];
    }



    int n;
    while(cin >> n){
        if(ways[n] > 1){
            printf("There are %.0f ways to produce %d cents change.\n", ways[n], n);
        } else {
            printf("There is only 1 way to produce %d cents change.\n", n);
        }
    }

}
