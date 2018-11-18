#include <iostream>
#include <string.h>
using namespace std;

string sol, guess;
int hasGuessed[26]; //0 for not in character list, 1 for is in list
                    //but not guessed, 2 for in list and guessed.
int round, wrongs, rights, totalChars;

int main(){
    while(cin >> round){
        if(round == -1) return 0;
        for(int i = 0 ; i < 26; i++){
            hasGuessed[i] = 0;
        }
        wrongs = rights = totalChars = 0;
        cin >> sol >> guess;
        int lS = sol.length(), lG = guess.length();
        for(int i = 0 ; i < lS; i++){
            if(!hasGuessed[sol[i] - 'a']) {
                //cout << "Now: " << sol[i] << endl;
                totalChars++;
            }
            hasGuessed[sol[i] - 'a'] = 1;
        }
        cout << "Round " << round << endl;
        for(int i = 0; i < lG; i++){
            if(hasGuessed[guess[i] - 'a'] <= 0){
                if(hasGuessed[guess[i] - 'a'] == 0)
                    wrongs++;
                //cout << "hasguessed[" << guess[i] << "] = " << hasGuessed[guess[i] - 'a'] << endl;
                hasGuessed[guess[i] - 'a'] = -1;
            } else {
                if(hasGuessed[guess[i] - 'a'] == 1)
                    rights++;
                hasGuessed[guess[i] - 'a'] = 2;

            }
            //cout << "at char " << i << ", wrongs: " << wrongs << ", rights: " << rights << endl;
            if(wrongs == 7){
                cout << "You lose." << endl;
                break;
            } else if(rights == totalChars){
                cout << "You win." << endl;
                break;
            } else if(i == lG - 1){
                cout << "You chickened out." << endl;
            }
        }
    }
}
