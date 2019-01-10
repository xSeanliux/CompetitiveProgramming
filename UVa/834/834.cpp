#include <iostream>
#include <math.h>
using namespace std;

int numerator, denominator;
int values[1000000];
int main(){
    while(cin >> numerator >> denominator){
        cout << "[" << floor(numerator/denominator);//integer part
        int i = 0;
        if(numerator % denominator == 0){
            cout << "]" << endl;
            continue;
        }
        cout << ";";
        numerator %= denominator;
        //cout << numerator << " " << denominator << endl;
        swap(numerator, denominator);
        //cout << "hey" << endl;
        do{
            values[i] = floor(numerator/denominator);
            //cout << "yo" << endl;
            //cout << numerator << " " << denominator << endl;
            i++;o
            numerator %= denominator;
            swap(numerator, denominator);

        }while(numerator > 1 && numerator != 1);

        for(int j = 0; j < i-1; j++){
            cout << values[j] << ",";
        }
        cout << values[i-1] << "]" << endl;
    }
}
