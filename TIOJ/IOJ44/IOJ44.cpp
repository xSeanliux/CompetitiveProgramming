#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

string s;

int main(){
    vector<int> AB, BA;
    cin >> s;
    for(int i = 0; i < s.length() - 1; i++){
        if(s.substr(i, 2) == "AB") AB.push_back(i);
        if(s.substr(i, 2) == "BA") BA.push_back(i);
    }
    bool isBang = false;
    for(int a : AB){
        for(int b : BA){
            if(abs(a - b) >= 2){
                isBang = true;
                cout << "BANG!" << endl;
                return 0;
            }
        }
    }
    cout << "Lovelive!" << endl;
}
