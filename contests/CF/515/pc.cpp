#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;

map <string, int> lib;
int maxL = 0, maxR = 1, c;
char com;
string arg;

int main(){
    cin >> c;
    for(int ia = 0; ia < c; ia++){
        cin >> com >> arg;
        if(com == 'L'){
            lib.insert(pair<string , int>(arg, maxL));
            maxL--;
        } else if(com == 'R'){
            lib.insert(pair<string , int>(arg, maxR));
            maxR++;
        } else if(com == '?'){
            int ind = lib[arg];
            cout << min(abs(ind - maxR), abs(ind - maxL)) - 1 << endl;
        }
    }
}
