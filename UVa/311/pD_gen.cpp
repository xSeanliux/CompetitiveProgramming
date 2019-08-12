#include <iostream>
using namespace std;

int main(){
    printf("200000 10\n");
    for(int i = 1; i <= 200000; i++) printf(" %d", i);
    for(int i = 1; i <= 10; i++){
        printf("1 %d %d 1", i, i);
    }
}
