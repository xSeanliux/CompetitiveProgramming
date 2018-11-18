#include <iostream>
using namespace std;




int N;
int main(){

    while(cin >> N){
        int friends[N];
        int groups = 0;
        bool visited[N];
        for(int i = 0; i < N; i++){
            cin >> friends[i];
            visited[i] = false;
        }
        //int groups = dfs(N, friends, visited, 0);


        int currentFriend;
        for(int i = 0; i < N; i++){
            if(visited[i] == false){
                groups++;


                int currentFriend = i;
                while(visited[currentFriend] == false){
                    visited[currentFriend ] = true;
                    currentFriend = friends[currentFriend];
                }
            }
        }
        cout << "GROUPS: " << groups << endl;





    }


}

