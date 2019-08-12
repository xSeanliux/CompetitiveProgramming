#pragma gcc optimize ("O2")
#include <vector>
#include <iomanip>
#include <math.h>
#include <iostream>
using namespace std;
#define int long long
int n, m, mx;
#define M 5
#define BASE 100
#define pc(x) putchar_unlocked(x);
bool flag = false;
inline void writeInt (int n){
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

vector<int> v[M];



int price_now[M], result[M], all_price[1<<M], target[M], mem[8][100005];

inline int get_prob(int x, int ind){ // O(m)
    //get the probablilty of the ind'th item with seed x
    int ans = 1, i = 0;
    for(int i = 0; i < m; i++){
        if(x&(1<<i))
            ans *= (BASE-v[i][ind]); //1 - not
        else ans *= BASE;
    }
    return mx - ans;
}

inline int get_prob_2(int x, int ind){ // O(m)
    //get the probablilty of the ind'th item with seed x
    if(mem[x][ind]) return mem[x][ind];
    int ans = 1, i = 0;
    for(int i = 0; i < m; i++){
        if(x&(1<<i))
            ans *= (BASE-v[i][ind]); //1 - not
        else ans *= BASE;
    }
    mem[x][ind] = mx - ans;
    return mem[x][ind];
}


inline void set_result(int x){
    int i = 0;
    do if(x&1)result[i]++;
    while(i++, x>>=1);
}
inline void setmax(int& maxs, int s, int& maxi, int i){
    if(s > maxs){
        maxs = s;
        maxi = i;
    }
}
inline void set_price(){
    all_price[0] = 0;
    for(int i = 0; i < m; i++) all_price[1<<i] = price_now[i];
    for(int i = 0; i < 1<<m; i++)
        all_price[i] = all_price[i-(i&-i)]+all_price[i&-i];
}
inline int getans(){
    for(auto& i:result)i = 0;
    int cur = 0;
    set_price();
    for(int ind = 0; ind < n; ind++){ // O(mn2^m)
        int maxs = cur, maxi = 0;
        for(int i = 0; i < 1<<m; i++) // O(2^m)
            setmax(maxs, cur+get_prob(i, ind)-all_price[i], maxi, i);// O(m)
        set_result(maxi);// O(m)
        cur = maxs;
    }
    return cur;
}

inline int getans_2(){
    for(auto& i:result)i = 0;
    int cur = 0;
    set_price();
    for(int ind = 0; ind < n; ind++){ // O(mn2^m)
        int maxs = cur, maxi = 0;
        for(int i = 0; i < 1<<m; i++) // O(2^m)
            setmax(maxs, cur+get_prob_2(i, ind)-all_price[i], maxi, i);// O(m)
        set_result(maxi);// O(m)
        cur = maxs;
    }
    return cur;
}

inline int bs(int lvl){
    if(lvl == m)
        return getans();
    int l = 0, r = mx, res;
    while(l+1 < r){
        int md = l+r>>1;
        price_now[lvl] = md - 1;
        res = bs(lvl+1);
        if(result[lvl] == target[lvl]) return res;
        else if(result[lvl] < target[lvl]) r = md;
        else l = md;
    }
    price_now[lvl] = l;
    return bs(lvl + 1);
}

inline int bs_2(int lvl){
    if(lvl == m)
        return getans_2();
    int l = 0, r = mx, res;
    while(l+1 < r){
        int md = l+r>>1;
        price_now[lvl] = md - 1;
        res = bs_2(lvl+1);
        if(result[lvl] == target[lvl]) return res;
        else if(result[lvl] < target[lvl]) r = md;
        else l = md;
    }
    price_now[lvl] = l;
    return bs_2(lvl + 1);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    if(m == 3 && n <= 100005) flag = true;
    for(int i = 0; i < m; ++i)cin >> target[i];
    if(m == 1) mx = 100;
    else if(m == 2) mx = 10000;
    else if(m == 3) mx = 1000000;
    else if(m == 4) mx = 100000000;
    for(int i = 0; i < m; ++i){
        v[i].reserve(n);
        for(int j = 0; j < n; j++){
            int o;cin >> o;
            v[i][j] = o;
        }
    }
    int res;
    if(flag) res = bs_2(0);
    else res = bs(0);
    for(int i = 0; i < m; ++i)res += target[i]*price_now[i];
    writeInt(res);
}
