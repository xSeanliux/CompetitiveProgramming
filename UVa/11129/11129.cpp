#include <iostream>
#include <vector>
using namespace std;

int N;

vector<int> ans;

vector<int> res(int N){
    if(N == 1){
        vector<int> v;
        v.push_back(0);
        return v;
    } else {
        vector <int> e, o, a;
        if(N % 2){
            e = res(N/2);
            o = res(N/2 + 1);
            for(int i = 0; i <= N/2; i++){
                a.push_back(2*o[i]);
            }
            for(int i = 0; i < N/2; i++){
                a.push_back(2*e[i] + 1);
            }
        } else{
            e = res(N/2);
            o = e;
            for(int i = 0; i < N/2; i++){
                a.push_back(2*e[i]);
            }
            for(int i = 0; i < N/2; i++){
                a.push_back(2*o[i] + 1);
            }
        }
        //cout << "The ans for n = " << N << endl;
        //for(int i = 0; i < N; i++){
        // cout << a[i] << " ";
        //}
        //cout << endl;
        return a;
    }
}

int main(){
    while(cin >> N){
        if(!N) return 0;
        ans = res(N);
        cout << N <<":";
        for(int i = 0; i < N; i++){
            cout << " " << ans[i];
        }
        cout << endl;
    }
}
