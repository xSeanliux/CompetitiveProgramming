#include <iostream>
#include <stack>
using namespace std;


int arr[100], li[100], ind[100], l;
stack <int> s;
int lis(){
    fill(li, li + l, 2147483647);
    for(int i = 0 ; i < l ; i++){
        int in = lower_bound(li, li + l, arr[i]) - li;
        ind[i] = in;
        *lower_bound(li, li + l, arr[i]) = arr[i];
    }
    return (lower_bound(li, li + l, 2147483647) - li);
}


int main(){
    cin >> l;
    for(int i = 0 ; i < l; i++){
        cin >> arr[i];
    }
    int k = lis();
    cout << k << endl;
    for(int i = l-1; i >= 0; i--){
        if(ind[i] == k-1){
            s.push(arr[i]);
            k--;
        }
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
