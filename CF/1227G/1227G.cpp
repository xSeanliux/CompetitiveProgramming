#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> indices, arr, vec;
vector<string> ans;
int N, x;


int main(){
    ericxiao;
    cin >> N;
    arr.resize(N);
    vec.resize(N);
    iota(vec.begin(), vec.end(), 0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(vec.begin(), vec.end(), [](int i, int j){
        return arr[i] < arr[j];
    });
    string s = "", _s;
    for(int i = 0; i < N; i++) s += '0';

    for(int i = 0; i < N; i++){
        if(arr[vec[N - 1]] == 1) break;
        if(!arr[vec[i]]) continue;
        _s = s;
        indices.clear();
        for(int j = i; j < N; j++){
            if(i == j || arr[vec[j]] > 1){
                _s[vec[j]] = '1';
                indices.push_back(vec[j]);
            }
        }
        cout << "Indices: " << endl;
        for(int x : indices) cout << x << " ";
        cout << endl;
        //ans.push_back(_s);
        for(int j = 1; j < indices.size(); j++){
            if(j <= arr[vec[i]]){
                _s[indices[j]] = '0';
                arr[indices[j]] -= (arr[vec[i]] - 1);
                ans.push_back(_s);
                _s[indices[j]] = '1';
            } else arr[indices[j]] -= (arr[vec[i]]);
        }
        arr[vec[i]] = 0;
        for(int i = 0; i < N; i++) cout << arr[i] << " \n"[i == N - 1];
    }
    if(arr[vec[N - 1]] == 1){
        _s = s;
        for(int i = 0; i < N; i++){
            if(arr[i] == 1) _s[i] = '1';
        }
        ans.push_back(_s);
    }
    cout << ans.size() << endl;
    for(string str : ans) cout << str << endl;
}
