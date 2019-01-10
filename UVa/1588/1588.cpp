#include <iostream>
#include <string.h>
using namespace std;

string a, b;
unsigned long int minAns;

bool checkShiftB(int offset){
    for(int i = offset; i < min(a.length(), b.length() + offset); i++){
        if(a[i] - '0' + b[i - offset] - '0' > 3) {
            return false;
        }
    }
    return true;
}

bool checkShiftA(int offset){
    for(int i = offset; i < min(a.length() + offset, b.length()); i++){
        if(a[i - offset] - '0' + b[i] - '0' > 3) {
            return false;
        }
    }
    return true;
}

int main(){
    while(getline(cin, a)){
        getline(cin, b);
        //cout << a.length() << "/" << b.length() << endl;
        for(int i = 0; i <= a.length(); i++){
            if(checkShiftB(i)){
                //cout << "Offset:" <<i << endl;
                minAns = max(a.length(), b.length() + i);
                break;
            }
        }
        for(int i = 0; i <= b.length(); i++){
            if(checkShiftA(i)){
                //cout << "Offset:" <<i << endl;
                minAns = min(minAns, max(a.length() + i, b.length()));
                break;
            }
        }
        cout << minAns << endl;
    }
}
