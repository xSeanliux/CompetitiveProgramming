#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string s;

int frq[10], re[4] = {1, 6, 8, 9};

int getval(){
    return (re[0] * 1000 + re[1] * 100 + re[2] * 10 + re[3]) % 7;
}


int main(){
    cin >> s;
    for(char c : s){
        frq[c - '0']++;
    }
    for(int n : re){
        frq[n]--;
    }
    string other = "";
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < frq[i]; j++){
            other += (char)(i + '0');
        }
    }
    int val = 0;
    for(int i = 0; i < other.length(); i++){
        val = (val * 10 + (other[i] - '0')) % 7;
    }
    val = val * (10000) % 7;
    do{
        if((getval() + val) % 7 == 0) break;
    } while(next_permutation(re, re + 4));
    for(int i = 0; i < 4; i++){
        other += (char)(re[i] + '0');
    }
    for(int i = 0; i < frq[0]; i++){
        other += '0';
    }
    cout << other << endl;
}
