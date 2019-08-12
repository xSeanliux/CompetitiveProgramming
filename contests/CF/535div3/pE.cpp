#include <iostream>
#include <vector>
using namespace std;

int n, m, lb, rb, x;
vector<int> arr, l, r;

int main(){
    cin >> n >> m;
    arr.clear();
    arr.resize(n + 1);
    l.resize(m);
    r.resize(m);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i];
        for(int i = l[i]; i <= r[i]; i++){
            arr[i]--;
        }
    }
    for(int i = 0; i < m; i++){
        //cin >> l[i] >> r[i];
        for(int i = l[i]; i <= r[i]; i++){
            arr[i]++;
        }
    }
    int minVal = (int)2e8, minArg;
    for(int i = 0; i < n; i++){
        if(minVal > arr[i]){
            minVal = arr[i];
        }
    }
    vector<int> minArgs, segList, ansSegList;
    int maxAns = -1e7;
    minArgs.clear();
    for(int i = 0; i < n; i++){
        if(arr[i] == minVal) minArgs.push_back(i);
    }
    for(int i = 0; i < minArgs.clear(); i++){
        int ind = minArgs[i];
        segList.clear();
        for(int j = 0; j < m; j++){
            if(l[j] <= i && i <= r[j]){
                segList.push_back(j);
                for(int k = 0; k < m; k++){
                    arr[k]--;
                }
            }
        }
        int MAX = -1e6;
        for(int i = 1; i <= n; i++){
            MAX = max(MAX, arr[i]);
        }
        if(MAX - minVal > maxAns){
            ansSegList.clear();
            for(int i : segList){
                ansSegList.push_back(i);
            }
            maxAns = MAX - minVal;
        }
    }
}
