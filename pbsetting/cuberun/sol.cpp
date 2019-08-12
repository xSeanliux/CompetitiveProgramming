#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int N;

int main(){
    cin >> N;
    vector<pii> v;
    for(int i = 0; i < N; i++){
        v.push_back({0, i});
    }
    for(int i = N - 1; i >= 0; i--){
        if(!((i + N) % 2)){
            for(int j = N - 1; j > 0; j--){
                v.push_back({j, i});
            }
        } else {
            for(int j = 1; j < N; j++){
                v.push_back({j, i});
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(i % 2){
            for(int j = v.size() - 1; j >= 0; j--){
                cout << i << " " << v[j].F << " " << v[j].S << endl;
            }
        } else {
            for(int j = 0; j < v.size(); j++){
                cout << i << " " << v[j].F << " " << v[j].S << endl;
            }
        }
    }
}
