#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

int N;
vector<int> data[2]; //0 for start with F, 1 for start with M
vector<string> inds; //the
bool visited[50], hasLoop;
string s;

void dfs(int id, int depth, char lastChar){
    if(depth == inds.size()){
        //check if last one can connect to first
        if(lastChar == inds[0][0]) hasLoop = true;
        return;
    }
    if(lastChar == 'F'){
        for(int i = 0; i < data[1].size(); i++){
            if(!visited[data[1][i]]){
                visited[data[1][i]] = true;
                dfs(data[1][i], depth + 1);
                visited[data[1][i]] = false;
            }
        }
    }
}

int main(){
    cin >> N;
    getline(cin, s);
    while(N--){
        getline(cin, s);
        stringstream strm(s);
        for(string x; strm >> s;){
            if(x[0] > x[1]) swap(x[0], x[1]);
            if(x[0] != x[1]){
                data[0].push_back(inds.size());
                data[1].push_back(inds.size());
            } else if(x[0] == 'M'){
                data[1].push_back(inds.size());
            } else {
                data[0].push_back(inds.size());
            }
            inds.push_back(x);
        }
        cout << "ok" << endl;
        for(int i = 0; i < inds.size(); i++) visited[i] = false;
        hasLoop = false;
        dfs(0, 0);
        if(hasLoop) cout << "LOOP" << endl;
        else cout << "NO LOOP" << endl;
    }
}
