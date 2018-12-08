#include <iostream>
using namespace std;

int a[1000000 + 5], b[1000000 + 5];
int m, n;

int binarySearch(int val, int arr[], int len){
    //cout << "Searching for " << val << endl;
    int u = len;
    int l = 0;
    int m = (u + l)/2;
    while(u >= l){
        if(arr[m] > val){
            u = m - 1;
        } else if(arr[m] < val){
            l = m + 1;
        } else {
            //cout << "Found " << val << endl;
            return m;
        }
        //cout << l << " " << u << endl;
        m = (u + l)/2;
    }
    return -1;
}

int main(){
    while(cin >> m >> n){
        if(!m && !n) return 0;

        for(int i = 0; i < m; i++){
            cin >> a[i];
        }
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(binarySearch(b[i], a, m) >= 0){
                total++;
            }
        }
        cout << total << endl;


    }
}
