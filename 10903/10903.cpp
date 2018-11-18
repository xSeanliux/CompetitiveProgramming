#include <iostream>
#include <string.h>
using namespace std;

struct Player{
    int wins, losses;
} players[1005];

int N, K, pA, pB; //N players, K matches
string s1, s2;
bool c = false;

int play(string s1, string s2){
    if(s1 == s2){
        return 0;
    }
    if(s1 == "rock"){
        if(s2 == "paper"){
            return -1;
        } else return 1;
    }
    if(s1 == "paper"){
        if(s2 == "scissors"){
            return -1;
        } else return 1;
    }
    if(s1 == "scissors"){
        if(s2 == "rock"){
            return -1;
        } else return 1;
    }
}


int main(){
    while(cin >> N){
        if(!N) return 0;
        cin >> K;
        for(int i = 1; i <= N; i++){
            players[i].wins = players[i].losses = 0;
        }
        for(int i = 0 ; i < K*(N)*(N-1)/2; i++){
            cin >> pA >> s1 >> pB >> s2;
            int res = play(s1, s2);
            if(res == 1){ //pA win
                players[pA].wins++;
                players[pB].losses++;
            } else if(res == -1) { //pB win
                players[pB].wins++;
                players[pA].losses++;
            }
        }
        if(!c)
            c = true;
        else
            cout << endl;

        for(int i = 1; i <= N; i++){
            if(players[i].wins + players[i].losses == 0)
                cout << "-" << endl;
            else
                printf("%.3f\n", (players[i].wins+0.0)/(players[i].wins + players[i].losses) );
        }

    }
}
