#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
const int maxC = 300, maxN = 4e5 + 10;
const long long int MOD = 1e9 + 7;

int N, Q, x, l, r, arr[maxN];
long long int mult, mask, mt[100], msk[maxC + 10];
vector<long long int > primes;
char com[maxC];

inline char readchar() {
    constexpr int B = 1<<20;
    static char buf[B], *p, *q;
    if(p == q && (q=(p=buf)+fread(buf,1,B,stdin)) == buf) return EOF;
    return *p++;
}
inline int nextint() {
    int x = 0, c = readchar();
    while(c < '0') c = readchar();
    while(c >= '0') x=x*10+(c^'0'), c=readchar();
    return x;
}

inline void readstr(char *s) {
    char c = readchar();
    while(c != ' ') *s++ = c, c = readchar();
}

inline long long int modpow(long long int b, int e){
    long long int r = 1, c = b;
    for(int i = 0; i < 30; i++){
        if((e >> i) & 1) r = r * c % MOD;
        c = c * c % MOD;
    }
    return r;
}

struct BitSeg{
    long long int seg[maxN * 2], tag[maxN * 2], h;
    BitSeg(){
        h = 25;
    }
    void build(){
        for(int i = N; i < 2 * N; i++) seg[i] = msk[arr[i - N]];
        for(int i = N - 1; i; i--) seg[i] = seg[(i << 1)] | seg[(i << 1) | 1];
    }
    inline void add(int pos, long long int val){
        seg[pos] |= val;
        if(pos < N) tag[pos] |= val;
    }
    inline void pull(int p){
        for(p >>= 1; p; p >>= 1) seg[p] = (seg[(p << 1)] | seg[(p << 1) | 1]) | tag[p];
    }
    inline void push(int p){
        for(int s = h; s; s--){
            int ind = p >> s;
            add((ind << 1), tag[ind]);
            add((ind << 1) | 1, tag[ind]);
            tag[ind] = 0;
        }
    }
    inline void modify(int l, int r, long long int m){
        l += N, r += N;
        int l0 = l, r0 = r;
        for(; l < r; l >>= 1, r >>= 1){
            if(l & 1) add(l++, m);
            if(r & 1) add(--r, m);
        }
        pull(l0);
        pull(r0 - 1);
    }
    inline long long int query(int l, int r){
        l += N;
        r += N;
        push(l);
        push(r - 1);
        long long int res = 0;
        for(; l < r; l >>= 1, r >>= 1){
            if(l & 1) res |= seg[l++];
            if(r & 1) res |= seg[--r];
        }
        return res;
    }
} bs;

struct Seg{
    long long int seg[maxN * 2], tag[maxN * 2], h;
    Seg(){
        h = 25;
        fill(seg, seg + maxN * 2, 1);
        fill(tag, tag + maxN * 2, 1);
    }
    void build(){
        for(int i = N; i < 2 * N; i++) seg[i] = arr[i - N];
        for(int i = N - 1; i; i--) seg[i] = seg[(i << 1)] * seg[(i << 1) | 1] % MOD;
    }
    inline void add(int pos, long long int val, int len){
        seg[pos] = seg[pos] * modpow(val, len) % MOD;
        if(pos < N) tag[pos] = tag[pos] * val % MOD;
    }
    inline void pull(int p){
        int len = 2;
        for(p >>= 1, len = 2; p; p >>= 1, len <<= 1)
            seg[p] = (seg[(p << 1)] * seg[(p << 1) | 1]) % MOD * modpow(tag[p], len) % MOD;
    }
    inline void push(int p){
        for(int s = h; s; s--){
            int ind = p >> s;
            add((ind << 1), tag[ind], (1 << (s - 1)));
            add((ind << 1) | 1, tag[ind], (1 << (s - 1)));
            tag[ind] = 1;
        }
    }
    inline void modify(int l, int r, long long int m){
        l += N, r += N;
        int l0 = l, r0 = r;
        for(int len = 1; l < r; l >>= 1, r >>= 1, len <<= 1){
            if(l & 1) add(l++, m, len);
            if(r & 1) add(--r, m, len);
        }
        pull(l0);
        pull(r0 - 1);
    }
    inline long long int query(int l, int r){
        l += N;
        r += N;
        push(l);
        push(r - 1);
        long long int res = 1;
        for(; l < r; l >>= 1, r >>= 1){
            if(l & 1) res =  res * seg[l++] % MOD;
            if(r & 1) res =  res * seg[--r] % MOD;
        }
        return res;
    }
} sg;

inline long long int getMask(int x){
    int r = 0;
    for(int i = 0; i < primes.size(); i++){
        if(!(x % primes[i])) r |= (1LL << i);
    }
    return r;
}

signed main(){
//    ericxiao;
    primes.push_back(2);
    bool f;
    for(int i = 3; i <= maxC; i += 2){
        f = true;
        for(int j = 0; j < primes.size(); j++){
            if(primes[j] * primes[j] > i) break;
            if(!(i % primes[j])){
                f = false;
                break;
            }
        }
        if(f) primes.push_back(i);
    }
    for(int i = 1; i <= maxC; i++) msk[i] = getMask(i);
    for(int i = 0; i < primes.size(); i++) mt[i] = ((primes[i] - 1) * modpow(primes[i], MOD - 2)) % MOD;
    N = nextint();
    Q = nextint();
    for(int i = 0; i < N; i++){
        arr[i] = nextint();
    }
    sg.build();
    bs.build();
    while(Q--){
        readstr(com);
        l = nextint();
        r = nextint();
        l--;
        if(com[0] == 'M'){
            x = nextint();
            bs.modify(l, r, msk[x]);
            sg.modify(l, r, x);
        } else {
            mask = bs.query(l, r), mult = sg.query(l, r);
            printf("mult = %lld, mask = %lld\n", mult, mask);
            for(int i = 0; i < primes.size(); i++){
                if((mask >> i) & 1) mult = mult * mt[i] % MOD;
            }
            printf("%lld\n", mult);
        }
    }
}
