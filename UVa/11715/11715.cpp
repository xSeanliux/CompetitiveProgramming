#include <iostream>
#include <math.h>
using namespace std;

/*
If 1 u v t are given then print s and a
If 2 u v a are given then print s and t
If 3 u a s are given then print v and t
If 4 v a s are given then print u and t
*/
//v0 = u, v = v
int com, c = 0;
double v0, v, t, a, s;

int main(){
    while(cin >> com){
        if(!com) return 0;
        printf("Case %d:", ++c);
        if(com == 1){
            //a = (v - v0)/t
            cin >> v0 >> v >> t;
            a = (v - v0)/t;
            s = a*t*t/2 + v0*t;
            printf(" %.03f %.03f\n", s, a);
        } else if(com == 2){
            cin >> v0 >> v >> a;
            t = (v-v0)/a;
            s = a*t*t/2 + v0*t;
            printf(" %.03f %.03f\n", s, t);
        } else if(com == 3){
            cin >> v0 >> a >> s;
            t = (-2*v0 + sqrt(4*v0*v0 + 8*a*s))/2/a;
            v = v0 + a*t;
            printf(" %.03f %.03f\n", v, t);
        } else if(com == 4){
            cin >> v >> a >> s;
            t = (2*v - sqrt(4*v*v - 8*a*s))/2/a;
            v0 = v - a*t;
            printf(" %.03f %.03f\n", v0, t);
        }
    }
}
