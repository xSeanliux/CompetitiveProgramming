#include <iostream>
using namespace std;

long long int facts[10], current, counter, N;

void ready(){
    current = 1;
    facts[0] = 1;
    facts[1] = 1;
    for(int i = 2; i < 10; i++){
        facts[i] = facts[i-1] * i;
    }
}

int greedy(int N){
    counter = 0;
    while(N){
        for(int i = 9; i >= 0; i--){
            if(facts[i] <= N){
                //cout << facts[i] << " ";
                N -= facts[i];
                counter++;
                break;
            }
        }
    }
    return counter;
}

int main(){
    ready();
    while(cin >> N){
        printf("%d\n", greedy(N));
    }
}


