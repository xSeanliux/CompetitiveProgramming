#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int T, N;
string s;
struct Obj{ //a character
    int indeg, outdeg;
    char ances;
};

map<char, Obj> arr;

void sortOut(char a){
    if(arr[a].ances == a) return;
    sortOut(arr[a].ances);
    arr[a].ances = arr[arr[a].ances].ances;
}

void dsunion(char a, char b){
    if(arr[a].ances == arr[b].ances) return;
    sortOut(a);
    sortOut(b);
    arr[a].ances = arr[ arr[b].ances ].ances;
}


int main(){
    cin >> T;
    while(T--){
        cin >> N;
        arr = map<char, Obj>();
        for(int i = 0; i < N; i++){
            cin >> s;
            char startChar = s[0], endChar = s[s.length() - 1];
            if(!arr.count(startChar)){
                Obj o;
                o.indeg = 0, o.outdeg = 0;
                o.ances = startChar;
                arr.insert(pair<char, Obj>(startChar, o));
            }
            if(!arr.count(endChar)){
                Obj o;
                o.indeg = 0, o.outdeg = 0;
                o.ances = startChar;
                arr.insert(pair<char, Obj>(endChar, o));
            }
            arr[startChar].outdeg++;
            arr[endChar].indeg++;
            //cout << "outdeg of " << startChar << "++, and indeg of " << endChar << "++ " << endl;
            dsunion(startChar, endChar);
        }
        char c = '-';
        int numImore = 0, numOmore = 0;
        bool isGood = true;
        for(map<char, Obj>::iterator i = arr.begin(); i != arr.end(); i++){
            sortOut(i->first);
            if(c == '-') c = arr[i->first].ances;
            else if(arr[i->first].ances != c){
                isGood = false;
                break;
            }
            if(i->second.indeg != i->second.outdeg){
                if(i->second.indeg - i->second.outdeg == 1){
                    numImore++;
                } else if(i->second.indeg - i->second.outdeg == -1){
                    numOmore++;
                } else {
                    isGood = false;
                    break;
                }
                if(numImore > 1 || numOmore > 1){
                    isGood = false;
                    break;
                }
            }
       }
       if(isGood){
            cout << "Ordering is possible." << endl;
       } else {
            cout << "The door cannot be opened."<< endl;
        }
    }
}
