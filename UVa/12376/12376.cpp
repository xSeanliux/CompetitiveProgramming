#include <iostream>
using namespace std;

int T, nodes, routes, _t, from, to, c = 0;

int main(){
    cin >> T;
    while(T--){
        scanf("%d %d", &nodes, &routes);
        int nweight[nodes + 1], target[nodes];
        nweight[nodes] = -10000;
        for(int i = 0; i < nodes; i++){
            target[i] = nodes;
            scanf("%d", &_t);
            nweight[i] = _t;
        }
        for(int i = 0; i < routes; i++){
            scanf("%d %d", &from, &to);
            if(nweight[to] > nweight[ target[from] ]){
                target[from] = to;
            }
        }
        int currentNode = 0, lastNode, ans = 0;
        while(currentNode != nodes){
            ans += nweight[currentNode];
            currentNode = target[currentNode];
            if(target[currentNode] == nodes) lastNode = currentNode;
        }
        printf("Case %d: %d %d\n", ++c, ans, lastNode);
    }
}
