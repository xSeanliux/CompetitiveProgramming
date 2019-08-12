#include <iostream>
#include <vector>
using namespace std;

vector<int> ans, arr;
int N;

int main(){
    cin >> N;
    arr.resize(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(i && arr[i] == 1){
            ans.push_back(arr[i - 1]);
        }
    }
    ans.push_back(arr[N - 1]);
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
    cout << endl;
}
