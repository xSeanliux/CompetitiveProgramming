#include <iostream>
using namespace std;
int main(){
    string rightans;
    int numOfGuesses, a, b;
    string guess;
    while(cin >> rightans){
        a = 0 ; b = 0;
        cin >> numOfGuesses;
        for(int i = 0; i < numOfGuesses; i++){
            cin >> guess;
            for(int i = 0; i < 4; i++){
             if(rightans[i] == guess[i]){
                    a++;
            b--;
                }
                for(int j = 0; j < 4; j++){
                    if(rightans[i] == guess[j]){
                        b++;
                    }
                }
            }
            cout << a << "A" << b << "B" << endl;
        }
    }

}

