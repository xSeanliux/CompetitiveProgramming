#include <iostream>
using namespace std;

int possibleWays[10000];

int main(){
    for(int i = 0; i < 10000; i++){
        possibleWays[i] = 0;
    }
   possibleWays[0] = 1;
   for(int i = 1; i < 8000; i++){
        possibleWays[i] += possibleWays[i-1];
    }
    for(int i = 5; i < 8000; i++){
        possibleWays[i] += possibleWays[i - 5];
    }
    for(int i = 10; i < 8000; i++){
        possibleWays[i] += possibleWays[i - 10];
    }
    for(int i = 25; i < 8000; i++){
        possibleWays[i] += possibleWays[i - 25];
    }
    for(int i = 50; i < 8000; i++){
        possibleWays[i] += possibleWays[i - 50];
    }
    int a;
    while(cin >> a){
        cout << possibleWays[a] << endl;
    }
}
