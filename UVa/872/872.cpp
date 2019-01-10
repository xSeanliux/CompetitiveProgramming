#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#define MAX 26
using namespace std;

int T, charCount, deg[MAX];
string in;
map<char, vector<char> > adj;
map<char, int> indexes;
bool visited[MAX], flag = false, isPossible;
char charList[MAX], now[MAX];

void topodfs(int ite){
    //cout << "Running dfs(" << ite << ")" << endl;
    /*
    for(int i = 0 ; i < charCount; i++){
        cout << "deg(" << charList[i] << ") = " << deg[indexes[ charList[i] ]] << endl;
    }
    */
    if(ite == charCount){
        cout << now[0];
        for(int i = 1; i < charCount; i++){
            cout << " " << now[i];
        }
        cout << endl;
        isPossible = true;
        return;
    } else {
        for(int i = 0; i < charCount; i++){
            if(deg[i] == 0 && !visited[i]){
                //cout << "Chosen " << charList[i] << endl;
                now[ite] = charList[i];
                visited[i] = true;
                int L = adj[ charList[i] ].size();
                for(int j = 0 ; j < L; j++){
                    //cout << "deg(" << adj[ charList[i] ][j] <<") = " << deg[ adj[ charList[i] ][j] ] << endl;
                    deg[ indexes[ adj[ charList[i] ][j] ] ]--;
                    //cout << "deg(" << adj[ charList[i] ][j] <<") = " << deg[ adj[ charList[i] ][j] ] << endl;
                }
                topodfs(ite + 1);
                for(int j = 0 ; j < L; j++){
                    deg[ indexes[ adj[ charList[i] ][j] ] ]++;
                }
                visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> T;
    getline(cin, in);
    while(T--){
        isPossible = false;
        getline(cin, in); //buffer
        getline(cin, in); //chars
        charCount = 0;
        int l = in.length();
        for(int i = 0 ; i < l; i+=2){
            charList[charCount] = in[i];
            charCount++;
        }

        memset(visited, false, sizeof(visited));

        sort(charList, charList + charCount);
        for(int i = 0 ; i < charCount; i++){
            vector <char> v;
            deg[i] = 0;
            adj.insert(pair<char, vector<char> >(charList[i], v));
            indexes.insert(pair<char, int>(charList[i], i));
        }
        getline(cin, in); //order
        l = in.length();

        for(int i = 0 ; i < l; i++){
            char a = in[i], b = in[i + 2];
            adj[a].push_back(b);
            deg[indexes[b]]++;
            i += 3;
        }


        if(!flag){
            flag = true;
        } else {
            cout << endl;
        }
        topodfs(0);
        if(!isPossible)
            cout << "NO" << endl;
    }
}
