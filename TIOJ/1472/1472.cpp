#include <bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=2005;
const int inf=INT_MAX;
struct edge
{
    int to,cap,rev;
};
vector<edge> G[maxn];
bool used[maxn];
void add_edge(int from ,int to,int cap)
{
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{
    if(v==t)
        return f;
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        memset(used,false,sizeof(used));
        int f=dfs(s,t,inf);
        if(f==0)
            return flow;
        flow+=f;
    }
}
void ini(int n)
{
    for(int i=0;i<n;i++)
        G[i].clear();
}

int N, a, b;
vector<pii> segs;

bool cmp(pii a, pii b){
    return (a.F < b.F && b.S < a.S) ||(a.S < b.F);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    ini(2 * N + 20);
    //1: s
    //2N + 2: t
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        segs.emplace_back(a, b);
        add_edge(1, i + 2, 1);
        //cout << "For " << a << " " << b << endl;
        add_edge(i + N + 2, 2 * N + 2, 1);
        //cout << "1 " << i + 2 << endl;
        //cout << i + N + 2 << " " << 2 * N + 2 << endl;
        for(int j = 0; j < i; j++){
            //cout << "Looking at" << segs[j].F << " " << segs[j].S << endl;
            if(cmp(segs[j], segs[i])){
                add_edge(j + 2, i + N + 2, maxn);
                //cout << j + 2 << " " << i + N + 2 << endl;
            } else if(cmp(segs[i], segs[j])){
                add_edge(i + 2, j + N + 2, maxn);
                //cout << i + 2 << " " << j + N + 2 << endl;
            }
        }
    }
    cout << N - max_flow(1, 2 * N + 2) << endl;
    return 0;
}
