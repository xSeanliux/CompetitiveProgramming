#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<string, int> ids;
vector<int> dsu;
bool flag = true;


struct Edge{
    int a, b, w;
};

class Cmp{
public:
    bool operator()(Edge &lhs, Edge &rhs){
        return lhs.w > rhs.w;
    }
};




priority_queue<Edge, vector<Edge>, Cmp> pq;

int T, M, N, w;
string a, b;

void flat(int x){
    if(dsu[x] != x) flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void dsuUnion(int a, int b){
    flat(a); flat(b);
    dsu[dsu[a]] = dsu[b];
}

int main(){
    cin >> T;
    while(T--){
        cin >> M >> N;
        ids = map<string, int>();
        pq = priority_queue<Edge, vector<Edge>, Cmp>();
        dsu.clear();
        dsu.resize(M);
        for(int i = 0; i < M; i++) dsu[i] = i;
        for(int i = 0; i < N; i++){
                cin >> a >> b >> w;
                if(!ids.count(a)){
                    //cout << a << " is " << ids.size() << endl;
                    ids[a] = ids.size();
                }
                if(!ids.count(b)){
                    //cout << b << " is " << ids.size() << endl;
                    ids[b] = ids.size();
                }
                pq.push({ids[a], ids[b], w});
        }
        int added = 0, sum = 0;
        while(added < M - 1){
            Edge ft = pq.top();
            flat(ft.a); flat(ft.b);
            while(dsu[ft.a] == dsu[ft.b]){
                pq.pop();
                ft = pq.top();
                flat(ft.a); flat(ft.b);
            }
            sum += ft.w;
            dsuUnion(ft.a, ft.b);
            //cout << "Connecting " << ft.a << ", and " << ft.b << endl;
            pq.pop();
            added++;

        }
        if(flag) flag = false;
        else cout << endl;
        cout << sum << endl;
    }
}
