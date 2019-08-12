#include <iostream>
#include <string.h>
using namespace std;

int N;
string s;

char getGood(char a, char b){
    bool canDo[] = {1, 1, 1};
    if(a == 'R' || b == 'R') canDo[0] = false;
    if(a == 'G' || b == 'G') canDo[1] = false;
    if(a == 'B' || b == 'B') canDo[2] = false;
    for(int i = 0; i < 3; i++){
        if(canDo[i]){
            if(i == 0) return 'R';
            else if(i == 1) return 'G';
            else return 'B';
        }
    }
}

int main(){
    cin >> N >> s;
    int ans = 0;
    for(int i = 0; i < N - 1; i++){
        if(s[i] == s[i + 1]){ //switch this or switch next
            ans++;
            if(i < N - 2 && s[i] == s[i + 2]){ //switch next
                s[i + 1] = getGood(s[i], s[i + 2]);
            } else { //switch this
                s[i] = getGood(s[i - 1], s[i + 1]);
            }
        }
    }
    cout << ans << endl;
    cout << s << endl;
}
