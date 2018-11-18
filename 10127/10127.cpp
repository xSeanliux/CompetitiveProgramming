#include <iostream>
using namespace std;
int N;

int ans(int n, double current, long long int iteration){
    if((int)current % n == 0) return iteration;
    else return ans(n, 10*current + 1, iteration + 1);
}

int main(){
    for(int i = 1; i < 50; i++){
        if(i % 2 == 0 || i % 5 == 0) continue;
        printf("f(%d) : %d\n", i, ans(i, 1.0, 1));
    }
}
