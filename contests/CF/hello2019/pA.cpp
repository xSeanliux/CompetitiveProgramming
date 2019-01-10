#include <iostream>
#include <string.h>
#include <set>
using namespace std;

char s, n;
string card;
int main(){
    cin >> card;
    s = card[0], n = card[1];
    bool flag = false;
    for(int i = 0; i < 5; i++){
        cin >> card;
        if(card[0] == s || card[1] == n)flag = true;
    }
    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
