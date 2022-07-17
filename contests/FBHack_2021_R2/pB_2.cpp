#include <iostream>
#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <stack>
#include <sys/resource.h>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;


//code from http://sunmoon-template.blogspot.com/2015/07/heavy-light-decomposition.html
#include<vector>
#define MAXN 800026
typedef std::vector<int >::iterator VIT;
int siz[MAXN],max_son[MAXN],pa[MAXN],dep[MAXN];
/*節點大小、節點大小最大的孩子、父母節點、深度*/
int link_top[MAXN],link[MAXN], cnt, pre[MAXN], dfsord[MAXN], dfscnt;
/*每個點所在鏈的鏈頭、樹鏈剖分的DFS序、時間戳*/
std::vector<int >G[MAXN];/*用vector存樹*/
vector<int> frq[MAXN];

void dfs(){
    stack<pii> stk = stack<pii>();
    pii P;
    stk.emplace(1, 1);
    int u, p;
    while(stk.size()){
        P = stk.top(); stk.pop();
        p = P.F;
        u = P.S;
        dfsord[u] = dfscnt++;
        for(int x : G[u]) if(x != p){
            stk.emplace(u, x);
        }
    }
    
}

int T, N, u, v, belong[MAXN];
void find_max_son(){
    stack<int> stk = stack<int>();
    stk.push(1);
    int x;
    while(stk.size()){
        x = stk.top();
        stk.pop();
        siz[x]=1;
        max_son[x]=-1;
        for(VIT i=G[x].begin();i!=G[x].end();++i){
            if(*i==pa[x])continue;
            pa[*i]=x;
            dep[*i]=dep[x]+1;
            stk.push(*i);
            if(max_son[x]==-1||siz[*i]>siz[max_son[x]])max_son[x]=*i;
            siz[x]+=siz[*i];
        }
    }
}

void build_link(){
    stack<pii> stk = stack<pii>();
    stk.emplace(1, 1);
    pii P;
    int x, top;
    while(stk.size()){
        P = stk.top(); stk.pop();
        x = P.F;
        top = P.S;
        link[x]=++cnt;/*記錄x點的時間戳*/
        link_top[x]=top;
        if(max_son[x]==-1)return;
        stk.emplace(max_son[x],top);/*優先走訪最大孩子*/
        for(VIT i=G[x].begin();i!=G[x].end();++i){
            if(*i==max_son[x]||*i==pa[x])continue;
            stk.emplace(*i,*i);
        }
    }
}
inline void find_lca(int a,int b){
    //cout << "running findlca " << a << ", " << b << endl;
	/*求LCA，可以在過程中對區間進行處理*/
	int ta=link_top[a],tb=link_top[b];
	while(ta!=tb){
        //cout << "ta = " << ta << ", tb = " << tb << endl;
		if(dep[ta]<dep[tb]){
			std::swap(ta,tb);
			std::swap(a,b);
		}
		//這裡可以對a所在的鏈做區間處理 
		//區間為(link[ta],link[a])
        pre[link[ta]]++;
        pre[link[a] + 1]--;
        //cout << "a = " << a << ", ta = " << ta << endl;
        //cout << "adding [" << link[ta] << ", " << link[a]  << "]" << endl;
		ta=link_top[a=pa[ta]];
    }
    /*最後a,b會在同一條鏈，若a!=b還要在進行一次區間處理*/
    if(a != b){
        if(dep[a] > dep[b]) swap(a, b);
        //cout << "ok, a = " << a << ", b = " << b << endl;
        pre[link[a] + 1]++;
        pre[link[b] + 1]--;
    }

}

inline void solve(int tc){
    cin >> N;
    for(int i = 1; i <= N; i++){
        vector<int>().swap(G[i]);
        vector<int>().swap(frq[i]);
    }
    fill(pre, pre + N + 1, 0);
    fill(dep, dep + N + 1, 0);
    cnt = dfscnt = 0;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= N; i++){
        cin >> belong[i];
        frq[belong[i]].push_back(i);
    }
    find_max_son();
    build_link();
    dfs();
    for(int i = 1; i <= N; i++){
        sort(frq[i].begin(), frq[i].end(), [](int a, int b){
            return dfsord[a] < dfsord[b];
        });
        //cout << "frq[" << i << "] = " << frq[i].size() << endl;
        for(int j = 0; j < (int)frq[i].size() - 1; j++){
            find_lca(frq[i][j], frq[i][j + 1]);
        }
    }
    //for(int i = 1; i <= N; i++){
       // cout << "link[ " << i << " ] = " << link[i] << endl;
    //}
    for(int i = 1; i <= N; i++) pre[i] += pre[i - 1];
    int ans = N - 1;
    //for(int i = 1; i <= N + 1; i++){
        //cout << "pre[ " << i << " ] = " << pre[i] << endl;
    //}

    for(int i = 2; i <= N; i++){
        if(pre[link[i]]) ans--;
    }
    cout << "Case #" << tc << ": " << ans << endl;
}

signed main(){
    ericxiao
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
}

