#include <iostream>
using namespace std;

bool isLeap(int year){
    if(year % 400 == 0){return true;}

    if(year % 100 == 0){return false;}

    if(year % 4 == 0) {
        return true;
    } else{
        return false;
    }
}



int main(){
    int a, b, counter;
    while(cin >> a >> b){
        counter = 0;
        for(int i = a; i <=b; i++){
            if(isLeap(i)){
                cout << i << "is a leap year!" << endl;
                counter++;
            }

        }
        cout << counter << endl;
    }

}
