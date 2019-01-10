#include <iostream>
#include <string.h>
#include <set>
#include <vector>
using namespace std;

struct Obj{
    set <int> s;
    vector <int> vec;
};

int arr[200], N, encryptTimes;
string str;
bool flag = false;

int main(){
    while(cin >> N){
        if(!N) return 0;
        for(int i = 1 ; i <= N; i++){
            cin >> arr[i];
        }
        Obj go[N + 1];
        for(int i = 1; i <= N; i++){
            int currentGo = arr[i];
            go[i].vec.clear();
            go[i].vec.push_back(i);
            //cout << i << " : " << endl;
            while(!go[i].s.count(currentGo)){
                //cout << currentGo << " ";
                go[i].s.insert(currentGo);
                go[i].vec.push_back(currentGo);
                currentGo = arr[currentGo];
            }
            go[i].vec.pop_back();
            //cout << endl;
        }
        getline(cin, str);
        while(getline(cin, str)){
            if(str == "0") break;
            int l = str.length();
            for(int i = 0; i < l; i++){
                if(str[i] == ' '){
                    encryptTimes = stoi(str.substr(0, i));
                    str = str.substr(i + 1);
                    break;
                }
            }
            while(str.length() < N) str += ' ';
            char ansStr[N + 1];
            for(int i = 1 ; i <= N ; i++){

                ansStr[ go[i].vec[(encryptTimes) % go[i].vec.size()] ] = str[i-1];
            }
            for(int i = 1 ; i <= N; i++)
                cout << ansStr[i];
            cout << endl;
        }
        cout << endl;
    }
}
