#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N;
vector<int> v;
vector<pair<int, int> > ans;

int main(){
    cin >> N;
    v.resize(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= N; i++){
        while(i != v[i]){
            if((v[i] - i) >= N/2){
                ans.push_back({i, v[i]});
                swap(v[i], v[v[i]]);
            } else {
                if(v[i] > N/2){
                    if(i > N/2){
                        ans.push_back({1, i});
                        ans.push_back({1, v[i]});
                        ans.push_back({1, i});
                        swap(v[i], v[v[i]]);
                    } else {
                        ans.push_back({v[i], 1});
                        ans.push_back({i, N});
                        ans.push_back({1, N});
                        ans.push_back({i, N});
                        ans.push_back({v[i], 1});
                        swap(v[i], v[v[i]]);
                    }
                } else {
                    ans.push_back({i, N});
                    ans.push_back({N, v[i]});
                    ans.push_back({v[i], N});
                    swap(v[i], v[v[i]]);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(auto p : ans) cout << p.first << " " << p.second << endl;
}
