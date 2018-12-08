#include <iostream>
#include <string.h>
using namespace std;

string s, t;
int N;

int main(){
    cin >> N;
    getline(cin, t);
    for(int i = 0 ; i < N; i++){
        getline(cin, s);
        int score = 0;
        int currentScore = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'O'){
                currentScore++;
            } else {
                currentScore = 0;
            }
            score += currentScore;
        }
        cout << score << endl;
    }
}
