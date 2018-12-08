#include <iostream>
#include <string.h>
using namespace std;

int n;
string s1, s2;
bool isDoable;

bool isV(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}



int main(){
    cin >> n;
    for(int ka = 0 ;  ka < n; ka++){
        cin >> s1 >> s2;
        isDoable = true;
        int l1 = s1.length(), l2 = s2.length();
        if(l1 != l2){
            cout << "No" << endl;
            isDoable = false;
            continue;
        }
        for(int i = 0 ; i < l2; i++){
            if(!isV(s1[i]) && !isV(s2[i]) && s1[i] != s2[i]){
                cout << "No" <<endl;
                isDoable = false;
                break;
            } else if((isV(s1[i]) && !isV(s2[i])) || isV(s2[i]) && !isV(s1[i])){
                cout << "No" << endl;
                isDoable = false;
                break;
            }
        }
        if(isDoable)
            cout << "Yes" << endl;
    }
}
