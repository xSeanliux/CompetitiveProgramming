#include <iostream>
#include <string.h>
using namespace std;

int cases;
string currentNum;

struct Num{
    int digits[30];
    int head = 0;
    int decpt;
    int sign;
};

void displayNum(Num n){
    if(n.sign < 0){
        cout << "-";
    }
    for(int i = min(n.decpt, 0); i < n.head; i++){
        if(i < 0){
            cout << 0;
        }

            if(i == n.decpt+1) cout << '.';

        cout << n.digits[i];
    }
    cout << endl;
}


int main()
{
    Num currentSum;
    currentSum.sign = 1;
    for(int i = 0; i < 30; i++){
        currentSum.digits[i] = 0;
    }
    cout << "a" << endl;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> currentNum;
        cout << currentNum << endl;
        if(currentNum == "0"){
            //displayNum(currentSum);
            currentSum.sign = 1;
            for(int i = 0; i < 30; i++){
                currentSum.digits[i] = 0;
            }
            continue;
        } else {
            bool hasDot = false;
            Num cN;
            if(currentNum[0] == '-'){
                cN.sign = -1;
                currentNum = currentNum.substr(1);
            }

            for(int i = 0; i < currentNum.length(); i++){
                if(currentNum[i] == '.'){
                    cN.decpt = i;
                    hasDot = true;
                    while(cN.digits[i] == '0'){
                        i++;
                        cN.decpt--;
                    }
                } else {
                        cN.digits[cN.head] = currentNum[i] - '0';
                        cN.head++;
                }
                if(!hasDot && i == currentNum.length()-1){
                    cN.decpt = i+1;
                }
            }
            cout << cN.head << ", " << cN.decpt << endl;
            displayNum(cN);
        }
        //parse num;


    }

}
