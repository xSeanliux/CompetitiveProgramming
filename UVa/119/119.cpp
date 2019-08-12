#include <iostream>
#include <string>
#include <map>
using namespace std;

int T, people, amnt, sum;
string s, giver;
bool flag = false;
map<string, int> mp;

int main(){
    while(scanf("%d", &T) != EOF){
        mp = map<string, int>();
        int oriT = T;
        string names[T];
        for(int i = 0; i < T; i++){
            cin >> s;
            mp.insert(pair<string, int>(s, 0));
            names[i] = s;
        }
        for(int i = 0; i < T; i++){
            cin >> giver >> amnt >> people;
            if(!people) continue;
            sum += amnt;
            mp[giver] -= (amnt/people) * people;
            for(int i = 0; i < people; i++){
                cin >> s;
                mp[s] += amnt/people;
                //cout << giver << " : " << amnt << ", " << people << endl;
            }
        }
        if(flag){
            cout << endl;
        } else {
            flag = true;
        }
        for(string s : names){
            cout << s << " " << mp[s] << endl;
        }
    }
}
