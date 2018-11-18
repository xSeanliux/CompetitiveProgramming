#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 26
using namespace std;


map <char, vector<char> > adj;
map <char, int> indexes;
char now[MAX], charlist[MAX], allChars[MAX];
string in;
bool visited[MAX], hasEntered = false;
int charCount, deg[MAX];

void topodfs(int ite){
    //cout << "Running dfs(" << ite << ")." << endl;
    if(ite == charCount){
        for(int i = 0 ; i < charCount; i++){
            cout << now[i];
        }
        cout << endl;
        return;
    } else{
        for(int i = 0 ; i < charCount; i++){
            if(deg[i] == 0 && !visited[i]){ //remove the thing
                char c = charlist[i];
                //cout << "chosen: " << c << endl;
                now[ ite ] = c;
                visited[i] = true;
                for(int j = 0 ; j < adj[c].size(); j++){
                    deg[ indexes[ adj[c][j] ] ]--;
                }
                topodfs(ite + 1);
                for(int j = 0 ; j < adj[c].size(); j++){
                    deg[ indexes[ adj[c][j] ] ]++;
                }
                visited[i] = false;
            }
        }
    }
}


int main(){
    while(getline(cin, in)){
        charCount = 0;
        adj.clear();
        indexes.clear();
        int l = in.length();
        for(int i = 0; i < l; i += 2){
            /*
            charlist[i/2] = in[i];
            indexes.insert(pair<char, int>(in[i], i/2));
            */
            allChars[charCount] = in[i];
            charCount++;
        }

        sort(allChars, allChars + charCount);

        for(int i = 0 ; i < charCount; i++){
            charlist[i] = allChars[i];
            indexes.insert(pair<char, int>(allChars[i], i));
            deg[i] = 0;
            visited[i] = false;
            vector <char> v;
            adj.insert(pair<char, vector<char> >(allChars[i], v)); //init adj list
        }

        getline(cin, in); //orders
        l = in.length();
        for(int i = 0 ; i < l; i++){
            char a = in[i];
            i += 2;
            char b = in[i];
            i += 1;
            adj[a].push_back(b);
            //cout << a << " connected to " << b << endl;
            deg[indexes[b]]++;
            //cout << "Deg(" << b << ") is now " << deg[ indexes[b] ] << endl;
        }
        for(int i = 0 ; i < charCount; i++){
            //cout << "deg(" << charlist[i] << ") = " << deg[i] << endl;
        }
        if(!hasEntered){
            hasEntered = true;
        } else {
            cout << endl;
        }
        topodfs(0);
    }
}

