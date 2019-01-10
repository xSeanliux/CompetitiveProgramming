#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;


vector <int> disjoint, friendSize;
vector <string> names;

int C, N;
string s1, s2;

int sortOut(int ind){
    if(disjoint[ind] == ind){
        return ind;
    } else {
        sortOut(disjoint[ind]);
        disjoint[ind] = disjoint[disjoint[ind]];
        friendSize[ind] = friendSize[disjoint[ind]];
        return disjoint[ind];
    }
}


int main(){
    cin >> C;
    while(C--){
        map <string, int> indexes;
        disjoint.clear();
        names.clear();
        friendSize.clear();
        scanf("%d", &N);
        while(N--){
            cin >> s1 >> s2;
            //cout << s1 << ", " << s2 << endl;
            if(!indexes.count(s1)){
                indexes.insert(pair<string, int>(s1, indexes.size()));
                disjoint.push_back(disjoint.size());
                friendSize.push_back(1);
                names.push_back(s1);
            }
            if(!indexes.count(s2)){
                indexes.insert(pair<string, int>(s2, indexes.size()));
                disjoint.push_back(disjoint.size());
                friendSize.push_back(1);
                names.push_back(s2);
            }

            sortOut(indexes[s1]);
            sortOut(indexes[s2]);
            if(disjoint[indexes[s1]] != disjoint[indexes[s2]])
                friendSize[disjoint[indexes[s1]]] = friendSize[disjoint[indexes[s1]]] + friendSize[disjoint[indexes[s2]]];
            //friendSize[sortOut(indexes[s1])] = friendSize[sortOut(indexes[s1])] + friendSize[sortOut(indexes[s2])];
            disjoint[disjoint[indexes[s2]]] = disjoint[indexes[s1]];
            /*
            for(int i = 0 ; i < disjoint.size(); i++){
            //   sortOut(i);
                cout << "ancestor of " << names[i] << ": " << disjoint[i] << ", friendSize: " << friendSize[i] << endl;
            }
            */



            printf("%d\n", friendSize[disjoint[indexes[s1]]]);
        }
    }
}

