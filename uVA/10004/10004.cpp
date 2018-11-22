#include <iostream>
using namespace std;

int nodes, paths;

int p[205][205];
int colours[205];
bool isDoable = true;

void dfs(int node, int colour){
    if(!isDoable) return;
    if(colours[node] != 0 && colours[node] != colour){
        isDoable = false;
        return;
    } else {
        colours[node] = colour;
    }
    int othercolour = (colour == 1) ? 2 : 1;
    for(int i = 0; i < nodes; i++){
        if(p[node][i] == 1){
            p[node][i] = 2; //closed
            p[i][node] = 2;
            dfs(i, othercolour);
        }
    }
    return;
}


int main(){
    while(cin >> nodes){
        if(nodes == 0) return 0;
        cin >> paths;
        int a, b;
        isDoable = true;
        for(int i = 0; i < nodes; i++){
            colours[i] = 0; //no colour
        }
        for(int i = 0; i < paths; i++){
            cin >> a >> b;
            p[a][b] = p[b][a] = 1; //path open
        }
        dfs(0, 1); //two colours, named 1 and 2
        if(!isDoable){
            cout << "NOT BICOLORABLE." << endl;
        } else {
            cout << "BICOLORABLE." << endl;
        }
    }

}
