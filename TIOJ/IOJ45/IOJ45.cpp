#include <iostream>
#include <set>
using namespace std;

struct Obj{
    int colour, x, y;
    bool operator()(const Obj a, const Obj b){
        return a.colour < b.colour;
    }
};

int H, W, c;

set<Obj> s;

void dfs(Obj o){
    s.erase(o);
    Obj u = o;
    u.y--;
    if(s.count(u)){
        dfs(u);
    }
    Obj d = o;
    d.y++;
    if(s.count(d)){
        dfs(d);
    }
    Obj l = o;
    l.x--;
    if(s.count(l)){
        dfs(l);
    }
    Obj r = o;
    r.y--;
    if(s.count(r)){
        dfs(r);
    }
    Obj ul = o;
    u.y--;
    u.x--;
    if(s.count(ul)){
        dfs(ul);
    }
    Obj ur = o;
    u.y--;
    u.x++;
    if(s.count(ur)){
        dfs(ur);
    }
    Obj dl = o;
    u.y++;
    u.x--;
    if(s.count(dl)){
        dfs(dl);
    }
    Obj dr = o;
    u.y++;
    u.x++;
    if(s.count(dr)){
        dfs(dr);
    }
}

int main(){
    cin >> H >> W;
    Obj o;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            o.x = j;
            o.y = i;
            cin >> c;
            o.colour = c;
            if(c){
                s.insert(o);
            }
        }
    }
    //dfs
    int ans = 0;
    for(set<Obj>::iterator i = s.begin(); i != s.end(); i++){
        ans++;
        dfs(*i);
    }
    cout << ans << endl;
}
