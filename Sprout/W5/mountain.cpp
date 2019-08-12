#include <iostream>
#include <vector>
using namespace std;

long long int T, N;
vector<long long int> vec;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        vec.resize(N);
        vec.clear();
        vector<long long int> anss;
        anss.clear();
        for(int i = 0; i < N; i++) cin >> vec[i];
        bool currentInc = 1;
        //1 for inc, 0 for dec
        long long int ans = 0;
        for(int i = 1; i < N; i++){
            if(currentInc && vec[i] < vec[i-1]){
                ans++;
                anss.push_back(vec[i-1]);
                //cout << "Add at " << i << endl;
                currentInc = 0;
                //cout << "currentInc now " << currentInc << endl;
            } else if(!currentInc && vec[i] > vec[i-1]){
                ans++;
                anss.push_back(vec[i-1]);
                currentInc = 1;
                //cout << "Add at " << i << endl;
                //cout << "currentInc now " << currentInc << endl;
            }
        }
        if(currentInc){
            //cout << "Chosoe last" << endl;
            ans++;
            anss.push_back(vec[N-1]);
        }
        cout << ans << endl;

    }
}
