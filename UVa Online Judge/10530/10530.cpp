#include <iostream>
#include <string.h>
using namespace std;
int inf, sup, guess;
bool canGuess[11];
string ans, t;
int main(){
    inf = 0;
    sup = 10;
    for(int i = 1; i <= 10; i++){
        canGuess[i] = true;
    }
    while(cin >> guess){
        if(guess == 0) return 0;
        getline(cin, t); //dummy
        getline(cin, ans);
        //cout << ans << endl;
        if(ans == "too high"){
            for(int i = guess; i <= 10; i++){
               canGuess[i] = false;
            }
        } else if(ans == "too low"){
            for(int i = guess; i >= 1; i--){
               canGuess[i] = false;
            }
        } else {
            if(!canGuess[guess]){
                cout << "Stan is dishonest" << endl;
            } else {
                cout << "Stan may be honest" << endl;
            }
            for(int i = 1; i <= 10; i++){
                canGuess[i] = true;
            }
        }
    }

}
