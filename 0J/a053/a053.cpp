#include <iostream>
using namespace std;
int main(){
    int score, answered;
    while(cin >> answered){
        score = 0;
        if(answered >= 40){
            score = 100;
        } else if(answered >= 20 & answered < 40){
            score = 80 + answered - 20;

        } else if( answered > 10 & answered < 20){
            score = 60 + 2*(answered-10);
        } else if( answered <= 10){
            score = answered * 6;
        }
        cout << score << endl;

    }


}

