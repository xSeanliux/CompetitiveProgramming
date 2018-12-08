#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map <int , int> votes;
long long int N, currentMax;

int main(){
    cin >> N;
    int oriN = N;
    int _t;
    while(N--){
        scanf("%d", &_t);
        if(votes.count(_t)){
            votes[_t]++;
            if(votes[_t] > oriN/2){
                cout << _t << endl;
                return 0;
            }
        } else {
            votes.insert(pair<int, int>(_t, 1));
        }
    }
    for(map<int, int>::iterator i = votes.begin(); i != votes.end(); i++){
        //cout << i->first << ": " << i->second << endl;
        if(i->second > oriN/2){
            //cout << i->second << ">" << N/2 << endl;
            cout << i->first << endl;
            return 0;
        }
    }
}


