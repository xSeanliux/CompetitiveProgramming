#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long int
using namespace std;

int T, N, x, y;

struct Point{
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y){}
};

inline int cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(Point a, Point b){
    return (a.x == b.x ? a.y < b.y : a.x < b.x);
}


signed main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> N;
        Point points[N], ch[N];
        for(int i = 0; i < N; i++){
            cin >> x >> y;
            points[i] = Point(x, y);
        }
        sort(points, points + N, cmp);
        int m = 0;
        for(int i = 0; i < N; i++){
            while(m >= 2 && cross(ch[m - 2], ch[m - 1], points[i]) <= 0) m--;
            ch[m++] = points[i];
        }
        for(int i = N - 2, lowlim = m + 1; i >= 0; i--){
            while(m >= lowlim && cross(ch[m - 2], ch[m - 1], points[i]) <= 0) m--;
            ch[m++] = points[i];
        }
        m--;
        int ans = 0;
        for(int i = 0; i < m - 1; i++){
            ans += ch[i].x * ch[i + 1].y - ch[i].y * ch[i + 1].x;
        }
        ans += ch[m - 1].x * ch[0].y - ch[0].x * ch[m - 1].y;
        if(ans < 0) ans = -ans;
        cout << (ans >> 1);
        if(ans & 1) cout << ".5" << endl;
        else cout << ".0" << endl;
    }
}
