#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

const double PI = atan(1.0)*4, r = 10000;
double currents[1000 + 5], newCircle[2000 + 5], totalL, minLength;
bool visited[1000]; //don't know if we'll need this;
double currentG, addG;

int main(){
    while(cin >> currentG >> addG){
        totalL = 0;
        currents[0] = 0;
        for(int i = 1 ; i < currentG; i++){
            currents[i] = i/currentG;
            //cout << "currents[" << i << "] = " << currents[i] << endl;
        }
        newCircle[0] = 0;
        for(int i = 1 ; i < currentG + addG; i++){
            newCircle[i] = i/(currentG + addG);
            //cout << "newCircle[" << i << "] = " << newCircle[i] << endl;
        }

        for(int i = 1 ; i < currentG; i++){
            minLength = 10000000; //massive init
            for(int j = 1; j < currentG + addG; j++){
                double dA = abs(currents[i] - newCircle[j]);
                if(dA < minLength) minLength = dA;

            }
            //printf("Shortest dist to move %d st grave: %f 2pi rads\n", i+1, minLength);
            totalL += minLength;
        }
        double result = r * totalL;
        result *= 10000;
        result = round(result);
        result /= 10000;
        string st = to_string(result);
        //cout << st << endl;
        int k = st.length();
        while(st[--k] == '0'){
            //cout << st[k] << endl;
            st.pop_back();
            //cout << st << endl;
        }
        if(st[k] == '.') st += '0';
        cout << st << endl;
        //printf("%.4f\n", r * totalL); // my units are in 2pi rads lol
    }
}

