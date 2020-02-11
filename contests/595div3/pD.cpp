#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Seg{
    int l, r, id;
    Seg(){}
    Seg(int L, int R, int ID): l(L), r(R), id(ID){}
    bool operator<(const Seg s) const {
        return (r == s.r) ? id < s.id : r < s.r;
    }
};

int n, k, ans = 0;
vector<Seg> segs;
vector<int> todel;
set<Seg> st;

int main(){
    cin >> n >> k;
    segs.resize(n);
    for(int i = 0; i < n; i++){
        cin >> segs[i].l >> segs[i].r;
        segs[i].id = i;
    }
    sort(segs.begin(), segs.end(), [](Seg a, Seg b){
        return a.l < b.l;
    });
    int c;
    for(int i = 0; i < n; i++){
        c = i;
        while(i < n && segs[i].l == segs[c].l){
            st.insert(segs[i]);
            //cout << "Inserting " << segs[i].l << " " << segs[i].r << endl;
            i++;
        }
        i--;
        while(st.size() && st.begin()->r < segs[c].l){
            //cout << "Popping " << st.begin()->l << " " << st.begin()->r << endl;
            st.erase(st.begin());
        }
        while(st.size() > k){
            //cout << "Erasing " << st.rbegin()->l << " " << st.rbegin()->r << endl;
            todel.push_back(st.rbegin()->id);
            st.erase(prev(st.end()));
        }
    }
    cout << todel.size() << endl;
    for(int u : todel) cout << u + 1 << " ";
    cout << endl;
}
