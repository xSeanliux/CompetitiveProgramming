#include <iostream>
#include <string>
using namespace std;

string s;

int main(){
    while(cin >> s){
        int l = s.length();
        s += s[0];
        double emp = 0, hasB = 0, n = 0;
        for(int i = 0 ; i < l; i++){
            (s[i] - '0') ? hasB++ : emp++;
            if(s[i] == '0' && s[i+1] == '0') n++;
        }
        double stayProb = n/emp;
        double rotProb = emp/l;
        //printf("Stay: %f, Rotate: %f\n", stayProb, rotProb);
        if(stayProb > rotProb){
            printf("SHOOT\n");
        } else if(rotProb > stayProb){
            printf("ROTATE\n");
        } else {
            printf("EQUAL\n");
        }
    }
}
