#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxLog = 20;

vector<int> last, perm, arr, lastPos, point[maxLog], vec;
int n, m, q, l, r, k;

struct RMQ;

inline int getN(int ind){
    int res = ind;
    for(int i = 0; i < maxLog; i++){
        if((1LL << i) & (n - 1)) res = point[i][res];
        if(res == -1) return -1;
    }
    return res;
}

struct RMQ{
    vector<int> sparse[maxLog];
    RMQ(){}
    RMQ(vector<int> arr){
        for(int i = 0; i < maxLog; i++) sparse[i].resize(arr.size() + 5);
        for(int i = 0; i < arr.size(); i++){
            sparse[0][i] = arr[i];
        }
        for(int i = 1; i < maxLog; i++){ //len = (1LL << i)
            if((1LL << i) >= arr.size()) break;
            for(int j = 0; j <= arr.size() - (1LL << i); j++){
                sparse[i][j] = max(sparse[i - 1][j], sparse[i  - 1][j + (1LL << (i - 1))]);
            }
        }
    }
    int query(int l, int r){ //query [l, r)

        int len = r - l, k;
        for(k = 0; k < len; k++){
            if((1LL << k) <= len && (1LL << (k + 1)) > len) break;
        }
        //cout << "querying sparse[" << k << "][" << l << "], sparse[" << k << "][" << r - (1LL << k) << "]" << endl;
        return max(sparse[k][l], sparse[k][r - (1LL << k)]);
    }
} rmq;

int main(){
    ericxiao;
    cin >> n >> m >> q;
    last.resize(n);
    lastPos.resize(n);
    perm.resize(n);
    arr.resize(m);
    vec.resize(m);
    fill(lastPos.begin(), lastPos.end(), -1);
    for(int i = 0; i < maxLog; i++){
        point[i].resize(m);
    }
    for(int i = 0; i < n; i++){
        cin >> perm[i];
        perm[i]--;
    }
    for(int i = 0; i < n; i++){
        last[perm[i]] = perm[(i + n - 1) % n];
    }
    for(int i = 0; i < m; i++){
        cin >> arr[i];
        arr[i]--;
        if(lastPos[last[arr[i]]] == -1){
            for(int j = 0; j < maxLog; j++){
                point[j][i] = -1;
            }
        } else {
            point[0][i] = lastPos[last[arr[i]]];
            for(int j = 1; j < maxLog; j++){
                if(point[j - 1][i] == -1){
                    point[j][i] = -1;
                    continue;
                }
                point[j][i] = point[j - 1][ point[j - 1][i] ];
            }
        }
        //cout << "For arr[" << i << "] = " << arr[i] << endl;
        //cout << "Last found " << last[arr[i]] << " at " << lastPos[last[arr[i]]] << endl;
        //for(int j = 0; j < maxLog; j++) cout << point[j][i] << " ";
        //cout << endl << endl;
        vec[i] = getN(i);
        lastPos[arr[i]] = i;
    }
    //for(int i : vec){
    //    cout << i << " ";
    //}
    rmq = RMQ(vec);
    //cout << endl;
    while(q--){
        cin >> l >> r;
        l--;
        //cout << "Query result: " << rmq.query(l, r) << endl;
        cout << (rmq.query(l, r) >= l);
    }

}
