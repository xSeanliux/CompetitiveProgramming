#include <iostream>
using namespace std;

int a, b, c, L, d;

int f(int x){
    return a*x*x + b*x + c;
}

int main(){
    while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &L)){
        if(!(a || b || c || d || L)) return 0;
        int ans = 0;
        for(int i = 0 ; i <= L; i++){
            ans += (f(i) % d == 0);
        }
        printf("%d\n", ans);
    }
}
