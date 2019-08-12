#include <iostream>
#include <vector>
using namespace std;

const int bS = 400, MOD = 1000000009;
int N, M, x, l, r;

inline int add(int a, int b){
    if(a + b > MOD) return a + b - MOD;
    return a + b;
}

void getFib(int N){
    fib.clear();
    fib.resize(N);
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= N; i++) fib[i] = add(fib[i - 1], fib[i - 2]);
}

struct Block{
    vector<int> vals;
    int ans, add1, add2, s, e;
    Block(): ans(0), add1(0), add2(0){}
    Block(int block): s(s * block), e(s * block + bS - 1){}
    int valAt(int ind){
        return vals[ind - s];
    }
    void posAdd(int pos, int val){
        vals[pos] = add(val[pos], val);
        ans = add(ans, val);
    }
    void addNum(int x){
        vals.push_back(x);
        ans = add(x, ans);
    }
};

void modify(int l, int r){
    for(int i = l; i <= blocks[l/bS].e; i++){
        blocks[l/bS].posAdd(l - blocks[l/bS].s, fibs[i - l]);
    }
    int cFibI = blocks[l/bS].e - l + 2;
    for(int currentBlock = l/bS + 1; blocks[currentBlock].e < r; currentBlock++){
        blocks[currentBlock].add1 = add(blocks[currentBlock].add1, fibs[cFibI]);
        blocks[currentBlock].add2 = add(blocks[currentBlock].add2, fibs[cFibI + 1]);
        cFibI += bS;
    }
    for(int i = blocks[r/bS].s; i <= r; i++){
        blocks[l/bS].posAdd(i, fibs[cFibI++]);
    }
}

//TODO: write matrix multiplication
/*
[  0 1 ]^n
[  1 1 ]
*/

void arrExp(long long int &M[2][2], int exp){
    if(exp == 1) return;
    long long int _M[2][2] = {{
        M[0][0], M[0][1]
    }, {
        M[1][0], M[1][1]
    }};
    arrExp(_M, exp/2);
    _M[0][0] = (_M[0][0] * _M{0}[0] % MOD + _M[0][1] * _M{1}[0] % MOD ) % MOD;
    _M[0][1] = (_M[0][0])
}

int getNthSum(int a, int b, int n){ //a, b are 1st and 2nd terms
    /*
    [  0 1 ]^n+2 \/   [ a ]    - b
    [  1 1 ]     /\   [ b ]
    */

}

int query(int l, int r){
    //combine the ans :O
}

int main(){
    cin >> N >> M;
    Block blocks[N/bS + 1];
    for(int i = 0; i <= N/bS) blocks[i] = Block(i);
    for(int i = 0; i < N; i++){
        cin >> x;
        blocks[i/bS].addNum(x);
    }

}
