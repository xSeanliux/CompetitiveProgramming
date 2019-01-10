#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int N, M, k;
string s;
map <string, int> scores;

int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        cin >> s >> k;
        scores.insert(pair<string, int>(s, k));
    }
    int score = 0;
    for(int i = 0 ; i < M; i++){
        while(cin >> s){
            if(s == "."){
                cout << score << endl;
                score = 0;
                break;
            }
            if(scores.count(s)){
                score += scores[s];
            }
        }

    }
}
