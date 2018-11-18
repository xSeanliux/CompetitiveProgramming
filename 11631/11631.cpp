#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int disjoint[200000], n, m, a, b, w;


struct Path{
    int e;
    int s;
    int wei;
};

class cmp{
public:
    bool operator() (const Path &a, const Path &b) const{
        return a.wei > b.wei; //the less the better
    }
};



void sortOut(int ind){
    if(disjoint[ind] == ind){
        return;
    } else {
        sortOut(disjoint[ind]);
        disjoint[ind] = disjoint[disjoint[ind]];
    }
}


int main(){
    while(cin >> n >> m){
        //cin >> n >> m;
        if(!n && !m) return 0;
        priority_queue<Path, vector<Path>, cmp> paths;
        for(int i = 0; i < n; i++)
            disjoint[i] = i;
        int wSum = 0;
        for(int i = 0 ; i < m; i++){
            cin >> a >> b >> w;
            Path p;
            p.s = a;
            p.e = b;
            p.wei = w;
            wSum += w;
            paths.push(p);
        }

        int usedEdges = 0;

        while(!paths.empty() && usedEdges < n-1){
            Path p = paths.top();
            if(disjoint[p.s] != disjoint[p.e]){ //I want this edge
                disjoint[disjoint[p.s]] = disjoint[p.e];
                for(int i = 0; i < n; i++)
                    sortOut(i);
                usedEdges++;
                wSum -= p.wei;
            }
            paths.pop();
        }

        cout << wSum << endl;
    }

}
