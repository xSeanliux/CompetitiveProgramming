#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, k, arr[200005];
vector <int> current;
map <int, int> cnt;

bool canDo(int rep){ //can the array have rep repetitions?
    current.clear();
    for(map<int, int>::iterator i = cnt.begin(); i != cnt.end() && current.size() < k; i++){
        //cout << i->first << " has " << i->second << " occasions" << endl;
        if(i->second >= rep){
            int times = i->second/rep;
            for(int j = 0 ; j < times && current.size() < k; j++){
                current.push_back(i->first);
            }
        }
    }
    if(current.size() == k){
        return true;
    } else {
        return false;
    }
}

int main(){
    cin >> n >> k;
    int R;
    for(int i = 0; i < n; i++){
        cin >> R;
        if(!cnt.count(R)){
            cnt.insert(pair<int, int>(R, 1));
        } else{
            cnt[R]++;
        }
    }
    int U = n + 1;
    int L = 0;
    int M = (U + L)/2;
    vector <int> ansVec;
    //printf("U = %d, L = %d, M = %d\n", U, L, M);
    while(U - L > 1){
        ansVec.clear();
        if(canDo(M)){
            for(int i = 0 ; i < current.size(); i++){
                ansVec.push_back(current[i]);
            }
            L = M;
            //cout << "yes for " << M << endl;
            if(!canDo(M+1)){
                break;
            }
        } else {
            U = M;
        }
        M = (U + L)/2;
        //printf("U = %d, L = %d, M = %d\n", U, L, M);
    }
    for(int i = 0 ; i < ansVec.size(); i++){
        cout << ansVec[i] << " ";
    }
    cout << endl;
}
