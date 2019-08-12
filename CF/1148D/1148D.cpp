#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<pair<int, int> > s, t;
    int N, a, b;
    cin >> N;
    s.clear(); t.clear();
    for(int i = 1; i <= N; i++){
        cin >> a >> b;
        (a < b ? s : t).push_back({b, i});
    }
    if(s.size() < t.size()){
        cout << t.size() << endl;
        sort(t.begin(), t.end());
        for(auto i : t) cout << i.second << " ";
    } else {
        cout << s.size() << endl;
        sort(s.begin(), s.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        });
        for(auto i : s) cout << i.second << " ";
    }
}
