#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, a, m, A, M;

struct CRT {
    vector<int> M, A; //x = a (mod m)
    CRT() { vector<int>().swap(M); vector<int>().swap(A); }
    void add(int a, int m) { M.push_back(m); A.push_back(a); }
    int extgcd(int a, int b, int &x, int &y){
        if(!b){
            x = 1;
            y = 0;
            return a;
        }
        int _x, _y, d = extgcd(b, a % b, _x, _y);
        x = _y;
        y = (_x - (a / b) * _y);
        return d;
    }
    bool _solve(int a1, int m1, int a2, int m2, int &A, int &M){
        int q1, q2, d;
        d = extgcd(m1, m2, q1, q2);
        q2 = -q2;
        if((a1 - a2) % d) return false;
        q1 *= (a2 - a1) / d;
        q2 *= (a2 - a1) / d;
        //m1 * q1 - m2 * q2 = (a2 - a1)
        M = m1 / d * m2;
        //A = m1 * q1 % M + a1 % M
        //  = (m1 * q1) % (m1 * m2 / d)
        //ab % ac = a * (b % c)
        A = (m1 * (q1 % (m2 / d)) % M + a1 % M) % M;
        if(A < 0) A += M;
        return true;
    }
    int solve() {
        int _M = M[0], _A = A[0];
        for(int i = 0; i < (int)M.size(); i++) { if(!_solve(_A, _M, A[i], M[i], _A, _M)) return -1; }
        return _A;
    }
};

signed main(){
    ericxiao;
    while(cin >> N){
        if(!N) return 0;
        CRT crt = CRT();
        for(int i = 0; i < N; i++) {
           cin >> m >> a;
           crt.add(a, m);
        }
        cout << crt.solve() << endl;
    }
}
