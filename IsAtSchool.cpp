#include <iostream>
using namespace std;


string isAtSchool(int hour, int minutes){

    float time = hour + minutes/60.0;
    string AtSchool = (7.5 < time & time < 17) ? "At School" : "Not at School";
    return AtSchool;
}


int main(){
    int hour, minutes;
    while(true){
        cin >> hour >> minutes;
        if(hour && minutes && hour <= 23 && minutes <= 59){
            cout << isAtSchool(hour, minutes) << endl;
        } else {
            cout << "Invalid Input. Exiting.";
            break;
        }
    }

}
