#include <iostream>
#include <string>
using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, d, currentDate, currentWeekday, n;
int c;
string mon, day;

int main(){
    cin >> c;
    for(int ii = 0; ii < c; ii++){
        cin >> mon >> day;
        n = 0;
        currentDate = 1;
        if(mon == "JAN"){
            d = days[0];
        } else if(mon == "FEB"){
            d = days[1];
        } else if(mon == "MAR"){
            d = days[2];
        } else if(mon == "APR"){
            d = days[3];
        } else if(mon == "MAY"){
            d = days[4];
        } else if(mon == "JUN"){
            d = days[5];
        } else if(mon == "JUL"){
            d = days[6];
        } else if(mon == "AUG"){
            d = days[7];
        } else if(mon == "SEP"){
            d = days[8];
        } else if(mon == "OCT"){
            d = days[9];
        } else if(mon == "NOV"){
            d = days[10];
        } else if(mon == "DEC"){
            d = days[11];
        }
        if(day == "MON"){
            currentWeekday = 0; //0 for monday, 6 for sunday.
        } else if(day == "TUE"){
            currentWeekday = 1; //0 for monday, 6 for sunday.
        } else if(day == "WED"){
            currentWeekday = 2; //0 for monday, 6 for sunday.
        } else if(day == "THU"){
            currentWeekday = 3; //0 for monday, 6 for sunday.
        } else if(day == "FRI"){
            currentWeekday = 4; //0 for monday, 6 for sunday.
        } else if(day == "SAT"){
            currentWeekday = 5; //0 for monday, 6 for sunday.
        } else if(day == "SUN"){
            currentWeekday = 6; //0 for monday, 6 for sunday.
        }
        while(currentDate <= d){
            if(currentWeekday == 4 || currentWeekday == 5){
                n++;
            }
            currentDate++;
            currentDate;
            currentWeekday++;
            currentWeekday %= 7;
        }
        cout << n << endl;

    }
}
