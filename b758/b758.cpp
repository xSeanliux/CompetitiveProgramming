#include <iostream>
using namespace std;

int main(){

    int hr, minute;
    while(cin >> hr >> minute){
        if(minute + 30 >= 60){
            minute -= 30;
            hr += 1;
        } else {
            minute += 30;
        }

        if(hr + 2 >= 24){
            hr -= 22;

        } else {
            hr += 2;
        }
        printf("%02i:%02i", hr, minute);
    }

}
