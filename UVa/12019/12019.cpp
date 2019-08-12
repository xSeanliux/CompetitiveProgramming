#include <iostream>
#include <string.h>
using namespace std;

int T, M, D; //hehe

int main(){
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string dow[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cin >> T;
    while(T--){
        cin >> M >> D;
        int currentDay = 5;
        for(int i = 1; i < M; i++){
            currentDay += days[i];
            currentDay %= 7;
        }
        currentDay += D;
        currentDay %= 7;
        cout << dow[currentDay] << endl;
    }
}
