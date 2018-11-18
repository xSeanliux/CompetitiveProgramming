#include <iostream>
#include <algorithm>
using namespace std;

int c, n, t, s;
int arr[10000];
int main()
{
    cin >> c;
    for(int as = 0; as < c; as++){
        cin >> n;
        s = 0;
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cout << (arr[n-1] - arr[0]) * 2 << endl;
    }
}
