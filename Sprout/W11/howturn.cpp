#include <iostream>
#include <math.h>
#include <utility>
#define int long long int
using namespace std;

int N, l = 0, b = 0, r = 0;

struct Point{
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y){}
} p, pp, ppp; //point, prevpoint, prevprevpoint

signed main(){
    cin >> N;
    if(N < 3){
        cout << "0 0 0" << endl;
        return 0;
    }
    cin >> ppp.x >> ppp.y >> pp.x >> pp.y;
    for(int i = 2; i < N; i++){
        cin >> p.x >> p.y;
        if((p.x - pp.x) * (pp.y - ppp.y) - (p.y - pp.y) * (pp.x - ppp.x) > 0){
            l++;
        } else if((p.x - pp.x) * (pp.y - ppp.y) - (p.y - pp.y) * (pp.x - ppp.x) < 0){
            r++;
        } else if(((p.x - pp.x) * (pp.x - ppp.x) + (p.y - pp.y) * (pp.y - ppp.y)) * 1.0 / sqrt((p.x - pp.x) * (p.x - pp.x) + (p.y - pp.y) * (p.y - pp.y)) / sqrt((pp.x - ppp.x) * (pp.x - ppp.x) + (pp.y - ppp.y) * (pp.y - ppp.y)) + 1  < 1e-9) {
            b++;
        }
        swap(pp, ppp);
        pp = p;
    }
    cout << r << " " << l << " " << b << endl;
}
