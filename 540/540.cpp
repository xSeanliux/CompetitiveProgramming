#include <iostream>
#include <queue>
#include <map>
#include <string.h>
using namespace std;

int maxT, C = 0;
bool flag = false;

int main(){
    while(cin >> maxT){
        if(!maxT) return 0;
        map <int, int> belongs;
        for(int i = 0 ; i < maxT; i++){
            int k, a;
            cin >> k;
            while(k--){
                cin >> a;
                belongs.insert(pair<int, int>(a, i));
            }
        }
        queue <int> q, qT[maxT + 5]; //the actual queue and the queue for each of the teams
        string comm;
        int arg;
        printf("Scenario #%d\n", ++C);
        while(cin >> comm){
            if(comm == "STOP")
                break;
            else if(comm == "ENQUEUE"){
                //cout << "E" << endl;
                cin >> arg;
                int team = belongs[arg];
                if(qT[team].empty()){
                    //cout << "new: team " << team << endl;
                    q.push(team);
                }
                qT[team].push(arg);
                //cout << qT[team].size() << endl;;
            } else if(comm == "DEQUEUE"){
                //cout <<"D" << endl;
                int team = q.front();
                cout << qT[team].front() << endl;
                qT[team].pop();
                if(qT[team].empty()){
                    q.pop();
                }
            }
        }
        cout << endl;
    }
}
