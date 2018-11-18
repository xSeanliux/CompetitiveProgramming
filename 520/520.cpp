#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

string str;

int main(){
    while(cin >> str){
        if(str == "0:00") return 0;
        int l = str.length();
        int h, m;
        string cS;
        for(int i = 0; i < l; i++){
            if(str[i] == ':'){
                h = stoi(cS);
                cS = "";
            } else if(i == l-1){
                cS += str[i];
                m = stoi(cS);
            } else {
                cS += str[i];
            }
        }
        int degA = (30*abs(m-6))%180;
        int degB = (6*abs(m-30))%180;
        cout << degA << " " << degB << endl;
        if(degB > degA) swap(degA, degB);
        int r = degA-degB;
        cout << r <<".000" << endl;
    }
}

