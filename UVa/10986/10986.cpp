#include <iostream>
#include <vector>
#define INF 2000000000
using namespace std;

struct Edge{
    int to;
    int weight;
};
int k, c, nServers, nEdge, fromS, toS;
int a, b, d, ans;
vector<Edge> edges[50000 + 5];
int shortestInt[20000 + 5];
bool visited[20000 + 5];

int main(){
    cin >> k;
    //cout << " ka " << endl;
    for(int kk = 1; kk <= k; kk++){
        ans = -1;
        cin >> nServers >> nEdge >> fromS >> toS;
        //cout << " a " << endl;
        for(int i = 0 ; i <= nServers; i++){
            shortestInt[i] = INF;
            visited[i] = false;
            edges[i].clear();
        }
        //cout << "b" << endl;
        for(int i = 0 ; i < nEdge; i++){
            cin >> a >> b >> c; //from, to, weight
            Edge e;
            e.to = b;
            e.weight = c;
            edges[a].push_back(e);
            e.to = a;
            edges[b].push_back(e);
            //cout << "new edge from " << a << " to " << b << ", c = " << c << endl;
        }
        //cout << "c" << endl;
        shortestInt[fromS] = 0;
        int minVal = INF, minIndex = -1;
        Edge e;
        while(!visited[toS]){
            //cout << "cas" << endl;
            minVal = INF;
            minIndex = -1;
            for(int i = 0 ; i < nServers; i++){

                if(shortestInt[i] < minVal && !visited[i]){
                    minVal = shortestInt[i];
                    minIndex = i;
                }
            }
            //cout << "Chosen server no. " << minIndex << ", dist : " << shortestInt[minIndex] << endl;
            if(minIndex == -1) break;
            //the node labeled i is the one we want :)
            int s = edges[minIndex].size();
            for(int i = 0; i < s; i++){
                e = edges[minIndex][i];
                shortestInt[e.to] = min(shortestInt[e.to], shortestInt[minIndex] + e.weight);
                //cout << "shortestInt[" << e.to << "] = " << shortestInt[e.to]
// << endl;
            }
            visited[minIndex] = true;
        }
        printf("Case #%d: ", kk);
        if(shortestInt[toS] == INF){
            cout << "unreachable" << endl;
        } else {
            cout << shortestInt[toS] << endl;
        }
    }
}
