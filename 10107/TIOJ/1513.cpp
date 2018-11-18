#include <iostream>
#include <map>
#include <algorithm>
using namespace std;



int N, K;
long long int arr[100005];

int main(){
    while(cin >> N){
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        sort(arr, arr + N);
        bool flag = true;
        int ind = 0;
        int Len = (lower_bound(arr, arr + N, arr[ind]) - arr) + (upper_bound(arr, arr + N, arr[ind]) - arr);
                   // cout << "Len = " << Len << endl;

        while(!(Len % 2)){
            //cout << "Len = " << Len << ", i = " << ind << endl;
            ind += Len;
            //cout << "arr[ind] = " << arr[ind] << endl;
            Len = (upper_bound(arr, arr + N, arr[ind]) - arr) - (lower_bound(arr, arr + N, arr[ind]) - arr) ;
            //cout << "new len: " << Len << endl;
        }
        //cout << ind << endl;
        cout << arr[ind] << endl;
    }
}


