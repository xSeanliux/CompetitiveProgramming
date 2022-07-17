#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <utility>
#include <stack>
#include <unordered_map>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326, maxL = 18, INF = 1e10;



const bool DEBUG = 0;
int N, M, Q, u, v, w;
int cycle[maxN], dist[maxN], cycJump[maxL][maxN], sum[maxL][maxN], cycDep[maxN];

struct Edge {
    int u, v, w, id;
    Edge(){}
    Edge(int u, int v, int w, int id): u(u), v(v), w(w), id(id) {};
};

struct Data {
    int l, r, ans, sum;     
    Data(): l(0), r(0), ans(0), sum(0){}
    Data(int _l, int _r, int _ans, int _sum): l(_l), r(_r), ans(_ans), sum(_sum) {}
    inline void print() {
        if(DEBUG) cout << "l = " << l << ", r = " << r << ", ans = " << ans << ", sum = " << sum << endl;
    }
}jumps[maxL][maxN];

Data Merge(Data A, Data B) {
    Data d = Data(); 
    d.sum = A.sum + B.sum;
    d.l = max(d.l, A.l);
    d.l = max(d.l, A.sum + B.l);
    d.r = max(B.r, d.r);
    d.r = max(d.r, B.sum + A.r);
    d.ans = max(A.ans, B.ans);
    d.ans = max(d.ans, A.r + B.l);
    return d;
} 

struct Seg {
    Data seg[maxN * 8];
    int cnt = 0;
    Seg() { fill(seg, seg + maxN * 8, Data()); cnt = 0; }
    int addItem(int x) {
       Modify(0, 0, 2 * M, cnt, x);
       return cnt++;
    }
    void Modify(int id, int l, int r, int p, int v) {
        if(l + 1 == r) {
            int v_ = max(v, 0LL);
            seg[id] = {v_, v_, v_, v};
            return;
        }
        int m = (l + r) / 2;
        if(p < m) Modify(2 * id + 1, l, m, p, v);
        else Modify(2 * id + 2, m, r, p, v);
        seg[id] = Merge(seg[2 * id + 1], seg[2 * id + 2]);
    }
    Data Query(int id, int l, int r, int ql, int qr) {
        if(ql >= r || l >= qr) return Data();
        if(ql <= l && r <= qr) return seg[id];
        int m = (l + r) / 2;
        return Merge(Query(2 * id + 1, l, m, ql, qr), Query(2 * id + 2, m, r, ql, qr));
    }
    int getMax(int L, int l, int r, int R) {
        if(l > r) swap(l, r);
        Data d1 = Query(0, 0, 2 * M, l + 1, r + 1);
        Data d2 = Merge(Query(0, 0, 2 * M, r + 1, R), Query(0, 0, 2 * M, L, l + 1));
        if(DEBUG){
            cout << "getmax(" << L << " " << l << " " << r << " " << R << ")" << endl;
            d1.print();
            d2.print();
        }
        return max(d1.ans, d2.ans);
    }
} seg;

struct Cycle {
    int rep, totSum, maxSum, L, R;
    vector<int> vertices, weights;
    unordered_map<int, int> pos, dist, maxUp, maxDown, ans, pre;
    //dist is the max. dist from the rep 
    //any is the max dist to any node on the cycle
    //ans is the max subarray sum on some path from the point to the rep
    Cycle(): rep(0), vertices(vector<int>()), weights(vector<int>()) {}
    void get() {
        totSum = 0; //total sum of edge weights
        L = seg.cnt;
        for(int i = 0; i < (int)vertices.size(); i++) pos[vertices[i]] = seg.addItem(weights[i]);
        R = seg.cnt;
        for(int w : weights) totSum += w;
        pos.reserve(weights.size() * 5);
        dist.reserve(weights.size() * 5);
        maxUp.reserve(weights.size() * 5);
        maxDown.reserve(weights.size() * 5);
        ans.reserve(weights.size() * 5);
        pre.reserve(weights.size() * 5);
        
        maxSum = 0; //max cyclic subarray of weights
        int curSum = 0;
        for(int w : weights) {
            curSum = max(0LL, curSum + w);
            maxSum = max(maxSum, curSum);
        }
        curSum = 0;
        for(int w : weights) {
            curSum = max(0LL, curSum - w);
            maxSum = max(maxSum, totSum + curSum);
        }

        for(int i = 0; i < (int)vertices.size(); i++) {
            pre[vertices[i]] = i ? pre[vertices[i - 1]] + weights[i] : weights[i];
            //cout << "pre[" << vertices[i] << "] = " << pre[vertices[i]] << endl;
            dist[vertices[i]] = max(pre[vertices[i]], totSum - pre[vertices[i]]);
            if(i < (int)vertices.size() - 1) {
                ans[vertices[i]] = seg.getMax(L, pos[vertices[i]], pos[rep], R);
            }
        }
        //cout << "totsum = " << totSum << endl;

        multiset<int> lhs, rhs;
        lhs = rhs = multiset<int>();
        for(int i = 1; i < (int)vertices.size(); i++) {
            rhs.insert(pre[vertices[i]]);
        }
        maxDown[rep] = 0;
        for(int i = 0; i < (int)vertices.size() - 1; i++) {
            maxUp[vertices[i]] = max(dist[vertices[i]], 0LL);
            maxDown[vertices[i]] = max(dist[vertices[i]], 0LL);
            maxDown[rep] = max(maxDown[rep], dist[vertices[i]]);
            if(rhs.size()) {
                maxUp[vertices[i]] = max(maxUp[vertices[i]], (int)(*rhs.rbegin()) - pre[vertices[i]]);
                maxDown[vertices[i]] = max(maxDown[vertices[i]], totSum - (int)(*rhs.begin()));
            }
            if(lhs.size()) {
                maxUp[vertices[i]] = max(maxUp[vertices[i]], pre[vertices[i]] - (int)(*lhs.begin()));
                maxDown[vertices[i]] = max(maxDown[vertices[i]], (int)(*lhs.rbegin()));
            //cout << "maxUp[" << vertices[i] << "] = " << maxUp[vertices[i]] << endl;
            }
            //cout << "maxUp[" << vertices[i] << "] = " << maxUp[vertices[i]] << endl;
            lhs.insert(pre[vertices[i]]);
            rhs.erase(rhs.find(pre[vertices[i + 1]]));
        }
    }
    inline void print() {
        cout << "rep = " << rep << endl;
        cout << "totSum = " << totSum << endl;
        for(int x : vertices) cout << x << " "; cout << endl;
        for(int x : weights ) cout << x << " "; cout << endl;
    }
};

vector<Edge> adj[maxN], edges;
vector<Cycle> cycles;
vector<int> cycleAdj[maxN];

inline void addEdge(int u, int v, int w) {
    int id = edges.size();
    edges.emplace_back(u, v, w, id);
    adj[u].emplace_back(u, v, w, id);
    adj[v].emplace_back(v, u, w, id);
}

void cycDfs(int p = cycles.size() - 1, int u = cycles.size() - 1) {
    cycJump[0][u] = u;
    cycJump[1][u] = p;
    cycDep[u] = cycDep[p] + 1;
    for(int i = 2; i < maxL; i++) {
        cycJump[i][u] = cycJump[i - 1][u];
        cycJump[i][u] = cycJump[1][cycJump[i][u]];
        cycJump[i][u] = cycJump[i - 1][cycJump[i][u]];
    }
    for(int v : cycleAdj[u]) if(v != p) cycDfs(u, v); 
}

struct Tarjan {
    stack<Edge> stk;
    int vis[maxN], isCut[maxN];
    int low[maxN], dep[maxN];
    int N;
    inline void reset() {
        fill(vis, vis + N, 0);
        fill(low, low + N, 0);
        fill(dep, dep + N, 0);
        fill(isCut, isCut + N, 0);
        stk = stack<Edge>();
    }
    Tarjan(int _N): N(_N + 1) {
        reset();
    }
    inline void addCycle(int u, int v, int eid) {
        //cout << "adding " << u << " " << v << endl;
        Cycle cyc = Cycle();
        int cycId = cycles.size();
        Edge cyc_e;
        while(stk.size() && stk.top().id != eid) {
            cyc_e = stk.top(); stk.pop();
            cyc.vertices.push_back(cyc_e.u);
            cyc.weights.push_back( cyc_e.w);
            cycle[cyc_e.u] = cycId;
        }
        if(stk.size()) {
            cyc_e = stk.top(); stk.pop();
            cyc.vertices.push_back(cyc_e.u);
            cyc.weights.push_back( cyc_e.w);
            cyc.rep = cyc_e.u; 
        } else {
            cycle[u] = cycId;
            cyc.rep = u;
        }
        if(cyc.vertices.size() == 1) {
            cyc.vertices.push_back(cyc_e.v);
            cyc.weights.push_back(    -INF);
            reverse(cyc.vertices.begin(), cyc.vertices.end());
            reverse(cyc.weights.begin(), cyc.weights.end()); //makes sure rep is at the end
            cycle[cyc_e.v] = cycId;
        }
        cyc.get();
        cycles.push_back(cyc);
    }
    void dfs(int p, int u) {
        //cout << "dfs(" << p << ", " << u << ")" << endl;
           
        dep[u] = dep[p] + 1;
        low[u] = dep[u];
        //cout << "dep[" << p << "] = " << dep[p] << ", dep[" << u << "] = " << dep[u] << endl;
        vis[u] = true;
        int chi = 0;
        for(auto e : adj[u]) {
            int v = e.v;
            if(v != p) {
                if(!vis[v]) {
                    stk.push(e);
                    dfs(u, v);
                    chi++;
                    low[u] = min(low[u], low[v]);
                    if((u != p && low[v] >= dep[u]) || (u == p && chi > 1)){
                        isCut[u] = true;
                        addCycle(u, v, e.id); 
                    }                
                } else {
                    low[u] = min(low[u], dep[v]);
                    if(dep[v] < dep[u]) stk.push(e);
                }
            }    
        }
    }
    void run(int r = 1) {
        dfs(r, r);
        addCycle(r, -1, -1); 
        cycle[r] = cycles.size() - 1;
    }
};

signed main() {
    ericxiao
    cin >> N >> M >> Q;
    Tarjan bcc = Tarjan(N);
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    bcc.run();
    for(int i = 0; i < (int)cycles.size(); i++) {
        if(i != cycle[cycles[i].rep]) {
            cycleAdj[i].push_back(cycle[cycles[i].rep]);
            cycleAdj[cycle[cycles[i].rep]].push_back(i);
        }
    }
    cycDfs();
    for(int u = 1; u <= N; u++) {
        jumps[0][u] = Data(cycles[cycle[u]].maxUp[u], cycles[cycle[u]].maxDown[u], cycles[cycle[u]].ans[u], cycles[cycle[u]].dist[u]);
        if(DEBUG) cout << "jump " << 0 << " " << u << " "; jumps[0][u].print();
    }
    for(int i = 1; i < maxL; i++) {
        for(int u = 1; u <= N; u++) {
            int v = cycles[cycJump[i - 1][cycle[u]]].rep;
            //cout << "merging " << u << " and " << v << endl;
            jumps[i][u] = Merge(jumps[i - 1][u], jumps[i - 1][v]);
            if(DEBUG) if(i < 3) {
                cout << "jump " << i << " " << u << " "; jumps[i][u].print();
            }
        }
    }
    //cout << "1 belongs to " << cycle[1] << endl;
    while(Q--) {
        int a, b;
        cin >> a >> b;
        if(cycle[a] == cycle[b] || cycles[cycle[a]].rep == b || cycles[cycle[b]].rep == a) { //same cycle
            if(cycle[a] == cycle[b]) {
                int id = cycle[a]; 
                if(cycles[id].pos[a] > cycles[id].pos[b]) swap(a, b);
                cout << seg.getMax(cycles[id].L, cycles[id].pos[a], cycles[id].pos[b], cycles[id].R) << endl;
            } else if(cycles[cycle[a]].rep == b) {
                int id = cycle[a]; 
                cout << seg.getMax(cycles[id].L, cycles[id].pos[a], cycles[id].R - 1, cycles[id].R) << endl;
            } else {
                swap(a, b);
                int id = cycle[a]; 
                cout << seg.getMax(cycles[id].L, cycles[id].pos[a], cycles[id].R - 1, cycles[id].R) << endl;
            }
        } else {
            if(cycDep[cycle[a]] > cycDep[cycle[b]]) swap(a, b);     
            Data datA = Data(), datB = Data();
            int diff = cycDep[cycle[b]] - cycDep[cycle[a]];
            //cout << "diff = " << diff << endl;
            for(int i = maxL - 1; i >= 0; i--) {
                if((diff >> i) & 1) {
                    datB = Merge(datB, jumps[i][b]);
                    //cout << "merging: " << i << " " << b << endl; jumps[i][b].print();
                    b = cycles[cycJump[i][cycle[b]]].rep;
                }
            }
            assert(cycDep[cycle[a]] == cycDep[cycle[b]]);
            if(DEBUG) cout << "a = " << a << ", b = " << b << endl;
            if(DEBUG) datB.print();
            for(int i = maxL - 1; i >= 0; i--) {
                if(cycJump[i][cycle[a]] != cycJump[i][cycle[b]]) {
                    datA = Merge(datA, jumps[i][a]);
                    datB = Merge(datB, jumps[i][b]);
                    a = cycles[cycJump[i][cycle[a]]].rep;
                    b = cycles[cycJump[i][cycle[b]]].rep;
                }
            }
            //cout << "a = " << a << ", b = " << b << endl;
            assert(cycle[a] == cycle[b] || cycles[cycle[a]].rep == b || cycles[cycle[b]].rep == a);
            swap(datB.r, datB.l);
            int ans = 0;
            if(a == b) {
                datA = Merge(datA, datB);
                cout << datA.ans << endl;
            } else {
                int midDist = -1;
                //cout << "datA: "; datA.print();
                //cout << "datB: "; datB.print();
                if(cycles[cycle[a]].rep == b) {
                    midDist = cycles[cycle[a]].dist[a]; 
                    ans = max(datA.r + cycles[cycle[a]].maxUp[a], datB.l + cycles[cycle[a]].maxDown[a]);
                    ans = max(ans, seg.getMax(cycles[cycle[a]].L, cycles[cycle[a]].pos[a], cycles[cycle[a]].pos[b], cycles[cycle[b]].R));
                } else if(cycles[cycle[b]].rep == a){
                    ans = max(datA.r + cycles[cycle[b]].maxDown[b], datB.l + cycles[cycle[b]].maxUp[b]);
                    ans = max(ans, seg.getMax(cycles[cycle[b]].L, cycles[cycle[b]].pos[a], cycles[cycle[b]].pos[b], cycles[cycle[b]].R));
                    midDist = cycles[cycle[b]].dist[b];
                } else {
                    int posA = cycles[cycle[a]].pos[a];
                    int posB = cycles[cycle[a]].pos[b];
                    //cout << "posa = " << posA << ", posB = " << posB << endl;
                    if(posA > posB) swap(posA, posB);
                    midDist = seg.Query(0, 0, 2 * M, posA + 1, posB + 1).sum;
                    midDist = max(midDist, cycles[cycle[a]].totSum - midDist);
                    if(DEBUG) cout << "midDist = " << midDist << endl;
                    if(DEBUG) cout << "ans = " << ans << endl;
                    if(cycles[cycle[a]].pos[a] > cycles[cycle[a]].pos[b]){
                        swap(a, b);
                        swap(datA, datB);
                    }
                    int l = cycles[cycle[a]].pos[a], r = cycles[cycle[a]].pos[b], L = cycles[cycle[a]].L, R = cycles[cycle[a]].R;
                    Data d1 = seg.Query(0, 0, 2 * M, l + 1, r + 1); //ab
                    Data d2 = Merge(seg.Query(0, 0, 2 * M, r + 1, R), seg.Query(0, 0, 2 * M, L, l + 1)); //ba
                    ans = max(ans, datA.r + max(d1.l, d2.r));
                    ans = max(ans, datB.l + max(d1.r, d2.l));
                    if(DEBUG) {
                        cout << "datA: "; datA.print();
                        cout << "datB: "; datB.print();
                        cout << "d1: "; d1.print();
                        cout << "d2: "; d2.print();
                        cout << "posA = " << cycles[cycle[a]].pos[a] << ", posB = " << cycles[cycle[a]].pos[b] << endl;
                        cout << "Cycle: "; cycles[cycle[a]].print();
                    }
                    ans = max(ans, seg.getMax(cycles[cycle[a]].L, cycles[cycle[a]].pos[a], cycles[cycle[a]].pos[b], cycles[cycle[b]].R));
                    //cout << "midDist = " << midDist << endl;
                }
                ans = max(ans, datA.ans);
                ans = max(ans, datB.ans);
                ans = max(ans, datA.r + midDist + datB.l);
                cout << ans << endl;
            }
        }
    }
}

