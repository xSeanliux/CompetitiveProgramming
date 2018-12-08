#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int c;
bool hasPassedE; //has passed equals sign
char currentOp; //current operator
string s, currentS, newS;
string decs[1000];
int rC, rL, lC, lL, head, k; //right/left, constant and linear

int main(){
    cin >> c;
    for(int ii = 0; ii < c; ii++){
        cin >> s;
        rC = rL = lC = lL = 0;
        int l = s.length();
        hasPassedE = false;
        currentS = "";
        currentOp = '+';
        head = 0;
        //cout << s[0] << endl;
        for(int i = 0 ; i < l; i++){
            currentS += s[i];
            if(s[i] == '+' || s[i] == '-' || s[i] == 'x' || s[i] == '=' || i == l-1){
                decs[head] = currentS;
                if((currentS.back() == '-' ||currentS.back() == '+' || currentS.back() == '=') && currentS.length()-1){
                    newS = currentS.substr(0, currentS.length()-1);
                    decs[head] = newS;
                    //cout << newS << endl;
                    head++;
                    decs[head] = currentS.substr(currentS.length() - 1);
                    //cout << "new: " << decs[head-1] << endl;
                }
                //cout << decs[head] << endl;
                head++;
                currentS = "";
            }
        }
        for(int i = 0 ; i < head; i++){
            string currentS = decs[i];
            //cout << "CS: " << currentS << endl;
            if(currentS.back() == '='){
                hasPassedE = true;
                currentOp = '+';
            } else if(currentS.back() == '+'){
                currentOp = '+';
            } else if(currentS.back() == '-'){
                currentOp = '-';
            } else if(currentS.back() == 'x'){
                if(currentS.length() == 1){
                    //cout << "hey " << currentOp << endl;
                    k = 1;
                } else {
                    k = stoi(decs[i].substr(0, currentS.length() - 1));
                }
                //cout << currentS.substr(0, currentS.length() - 1) << endl;
                if(hasPassedE){ //RHS
                    if(currentOp == '+'){
                        rL += k;
                    } else if(currentOp == '-'){
                        rL -= k;
                    }
                } else { //LHS
                    if(currentOp == '+'){
                        lL += k;
                    } else if(currentOp == '-'){
                        lL -= k;
                         //cout << lL << endl;

                    }
                }
            } else {
                //cout << "Heya" << currentS << ", and: " << stoi(currentS) << endl;

                if(hasPassedE){
                    if(currentOp == '+'){
                        rC += stoi(currentS);
                    } else if(currentOp == '-'){
                        rC -= stoi(currentS);
                        //currentOp = '+';
                    }
                } else {
                    if(currentOp == '+'){
                        lC += stoi(currentS);
                    } else if(currentOp == '-'){
                        lC -= stoi(currentS);
                    }
                }
            }
             //printf("Simplifies to %dx + %d = %dx + %d\n", lL, lC, rL, rC);
        }

        rC -= lC;
        lL -= rL;
        lC = rL = 0;
        //printf("Simplifies to %dx = %d", lL, rC);
        if(rC == 0 && lL == 0){
            cout << "IDENTITY" << endl;
        } else if(lL == 0 && rC != 0){
            cout << "IMPOSSIBLE" << endl;
        } else {
            float t = floor((rC + 0.0)/(lL));
            if(!t) t = 0;
            printf("%.0f\n", t);
        }
        //cout << floor(-4.3) << endl;
        //printf("Simplifies to %dx + %d = %dx + %d", lL, lC, rL, rC);
        //printf("floor of solution: %.0f", floor((rC + 0.0)/(lL)));

    }
}
