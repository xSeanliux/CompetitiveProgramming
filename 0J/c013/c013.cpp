#include <iostream>
#include <string.h>
using namespace std;
string name;
int relation, cases;

int main(){
    while(cin >> cases){
        bool iLike = false;
        int likes = 0;
        int friendLikes = 0;
        string lastFriend = "";

        for(int i = 0; i < cases; i++){
            cin >> name >> relation;
            if(relation == 2){
                iLike = true;
            } else if(relation == 1){
                lastFriend = name;
                friendLikes++;
            }
            likes++;
        }

        if(likes - (friendLikes + iLike) > 0){ //people other than you and friends
            if(iLike && lastFriend != ""){
                cout << "You, " << lastFriend << " and " << likes - 2 << " others like this." << endl;
            } else if (iLike){
                cout << "You and " << likes-1 << " others like this." << endl;

            } else if(lastFriend != ""){
                cout << lastFriend << " and " << likes-1 << " others like this." << endl;

            } else {
                cout << likes << " people like this." << endl;

            }
        } else {
            if(iLike && lastFriend != ""){
                cout << "You and " << lastFriend << " like this." << endl;
            } else if(iLike){
               cout << "You like this." << endl;
            } else {
                cout << lastFriend << " like this." << endl;
            }
        }
    }
}
