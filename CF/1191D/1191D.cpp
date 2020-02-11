#include <iostream>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N;
vector<int> vec;

int main(){
    ericxiao;
    cin >> N;
    vec.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int sameTimes = 0;
    for(int i = 0; i < N - 1; i++){
        sameTimes += (vec[i] == vec[i + 1]);
        if(vec[i] == vec[i + 1]){
            if(vec[i - 1] == vec[i] - 1 || vec[i] == 0){
                cout << "cslnb" << endl;
                return 0;
            }
        }
    }
    //cout << sameTimes << endl;
    if(sameTimes > 1){
        cout << "cslnb" << endl;
        return 0;
    }
    long long int S = 0;
    for(int i = 0; i < N; i++){
        S += (vec[i] - i);
    }
    //cout << S << endl;
    if(S % 2){ //first
        cout << "sjfnb" << endl;
    } else { //second
        cout << "cslnb" << endl;
    }
}


