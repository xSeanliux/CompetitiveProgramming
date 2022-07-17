#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6, maxC = 1e6 + 326, maxB = 12, INF = 1e15;

bool isPrime[maxC];
vector<int> primes;
int N, K, B, dp[maxB][1 << maxB], minVal[1 << maxB], cost[maxB];
vector<int> has, sufprod, A, C;
map<int, priority_queue<int>> cls;
map<int, int> pows;
map<int, priority_queue<pii>> bestMask;
vector<vector<int>> toUpdate;

inline void sieve(){
    fill(isPrime, isPrime + maxC, true);
    isPrime[1] = false;
    for(int i = 2; i < maxC; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(i * p >= maxC) break;
            isPrime[i * p] = false;
            if(!(i % p)) break;
        }
    }
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

inline void preprocess(int x, int c){
    vector<int>().swap(has);
    int cl = 1;
    for(auto [p, id] : pows){
        while(!(x % p)){
            x /= p;
            cl *= p;
        }
    }
    if(!cls.count(cl)) cls[cl] = priority_queue<int>();
    cls[cl].push(c);
    if(cls[cl].size() > B) cls[cl].pop();
}

void dfs(int id, int now = 0, int cp = 1, int curmask = 0){
    if(now == B){
        if(!bestMask.count(curmask)) bestMask[curmask] = priority_queue<pii>();
        bestMask[curmask].push({C[id], id});
        if(bestMask[curmask].size() > B) bestMask[curmask].pop();
        return;
    }
    if(cp * cost[now] <= K) dfs(id, now + 1, cp * cost[now], curmask | (1LL << now));
    dfs(id, now + 1, cp, curmask);
}


signed main(){
    ericxiao;
    sieve();
    int p = 1;
    cin >> N >> K;
    A.resize(N);
    C.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    int g = A[0];
    for(int i = 0; i < N; i++) g = gcd(g, A[i]); 
    if(g == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int p : primes){
        if(p * p > g) break;
        if(!(g % p)){
            int k = pows.size();
            pows[p] = k;         
            while(!(g % p)) g /= p;
        }
    }
    if(g > 1){
        int k = pows.size();
        pows[g] = k;         
    }
    B = pows.size();
    for(int i = 0; i < N; i++){
        preprocess(A[i], C[i]);
    }
    vector<int>().swap(A);
    vector<int>().swap(C);
    for(auto &[val, costs] : cls){
        for(auto [p, id] : pows){
            cost[id] = 1;
            while(!(val % (cost[id] * p))){
                cost[id] *= p;
            }
            //cout << "cost of " << id << "(" << p << ") = " << cost[id] << endl;
        }
        while(costs.size()){
            A.push_back(val);
            //cout << "class = " << val << ", cost = " << costs.top() << endl;
            C.push_back(costs.top());
            dfs(A.size() - 1);
            costs.pop();
        }
    }
    N = A.size(); //N \approx 2e4
    toUpdate.resize(N);
    for(auto &[mask, pq] : bestMask){
        while(pq.size()){
            auto [cost, id] = pq.top();
            pq.pop();
            toUpdate[id].push_back(mask);
        }
    }
    for(int i = 0; i <= B; i++){
        for(int j = 0; j < (1 << B); j++) dp[i][j] = INF;
        dp[i][0] = 0;
    }
    for(int id = 0; id < N; id++){
        for(int i = B; i; i--){
            for(int j = 0; j < (1 << B); j++){
                for(int msk : toUpdate[id]){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j ^ (j & msk)] + C[id]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                }
            }
        }
    }
    int ans = INF;
    for(int cnt = 1; cnt <= B; cnt++){
        ans = min(ans, cnt * dp[cnt][(1 << B) - 1]);
    }
    if(ans == INF){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
