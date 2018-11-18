#include <iostream>
#include <math.h>
using namespace std;
const double PI = atan(1.0)*4;
int convert(string N){
    int sum = 0;
    //cout << "Converting: " << N << endl;
    for(int i = 1; i < 6; i++){ //from the first bit to the dot in the middle
        if(N[i]-' '){ //if it's not a space
            sum += pow(2, 8-i);
            //cout << "sum: "<< sum << endl;
        }
    }
    for(int i = 7; i < 10; i++){//from after the dot to the last bit
        if(N[i]-' '){ //if it's not a space
            sum += pow(2, 9-i);
            //cout << "sum: "<< sum << endl;
        }
    }
    return sum;
}


int main(){
    string currentTape;
    string str, tmp;
    int ok = 1;
    //cin >> tmp; // the start
    //cout << tmp << endl;
    while(getline(cin, currentTape)){
        if(currentTape == "___________"){
            ok = -1; //Checks if it's the end or not. Th

            if(ok == -1){ //The second time that you're here -> the first time I set it to -1
                //cout << "Str: ";
                cout << str;
                str = "";
                ok = 1;
                continue; //Might have more to decode
                //cout << "Ok is now" << ok << endl;
            }
            //cout << "Ok is now" << ok << endl;
            continue;
        } else {
            char N = convert(currentTape);
            //cout << N << endl;
            if((int)N != 255){
                str += N;
            }

        }
        //cout << str << endl;
    }
}
