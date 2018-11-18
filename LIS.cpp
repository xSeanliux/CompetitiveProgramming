#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;

int arr[10000], l;
int pos[10000];
stack<int> s;
int LIS(){
    vector<int> vec;
    vec.push_back(arr[0]); //prevent push_back from failing :D
    cout << "1 ";
    pos[0] = 1;
    for(int i = 1 ; i < l; i++){
        int x = arr[i];
        if(x > vec.back()){
            vec.push_back(x);
            pos[i] = vec.size();
            //cout << pos[i]
        }
        else {
            int K = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
            //cout << lower_bound(vec.begin(), vec.end(), x) << endl;
            pos[i] = K+1;
            //cout << *K << " ";
            *lower_bound(vec.begin(), vec.end(), x) = x; //push_back returns an iterator
        }
        cout << pos[i] << " ";
    }
    cout << endl;
    return vec.size();
}


int main(){
    while(cin >> l){
        s = stack<int>();
        assert(l < 10000);
        for(int i = 0 ; i < l; i++){
            cin >> arr[i];
        }
        int res = LIS();
        cout << res << endl;
        int Z = res;
        for(int i = l-1; i >= 0; i--){
            if(pos[i] == Z){
                s.push(arr[i]);
                //cout << arr[i]<<  " ";
                Z--;
            }
        }
        cout << endl;
        while(s.size()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}
