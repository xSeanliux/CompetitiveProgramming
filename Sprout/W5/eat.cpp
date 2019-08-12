#include <iostream>
#include <algorithm>
using namespace std;

struct Obj{
    long long int c, e;
    Obj(){}
    Obj(int a, int b): c(a), e(b){}
};

bool cmp(Obj a, Obj b){
    return a.e > b.e;
}

int N, g, h;

Obj objs[10005] ;

int main(){
    while(cin >> N){
            if(!N) return 0;
        for(int i = 0; i < N; i++){
            cin >> g >> h;
            objs[i] = Obj(g, h);
        }
        sort(objs, objs + N, cmp);
        long long int ans = 0, ct = 0;
        for(int i = 0; i < N; i++){
            ct += objs[i].c;
            ans = max(ct + objs[i].e, ans);
        }
        cout << ans << endl;
    }
}
