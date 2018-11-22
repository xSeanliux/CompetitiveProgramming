#include <iostream>
#include <queue>
using namespace std;

int arr[200];
bool visited[200];
int n, k, x;
priority_queue<int> pri;
int main(){
    cin >> n >> k >> x;
    if(k + (k-1)*x < n){
        cout << -1 << endl;
        return 0;
    }
    long long int ans = 0;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
        pri.push(arr[i]);
        visited[i] = false;
    }
    //every k needs to have a photo in it
    int currentM = 0, ind = 0;
    for(int i = 0 ; i < n; i += k){
        currentM = 0;
        for(int j = i; j < i + k; j++){
            if(arr[j] > currentM){
                currentM = arr[j];
                ind = j;
            }
        }
        i += (ind - i);
        visited[ind] = true;
        ans += currentM;
        x--;
    }
    while(x){
        currentM = 0;
        ind = 0;
        for(int i = 0 ; i < n; i++){
            if(currentM < arr[i] && !visited[i]){
                currentM = arr[i];
                ind = i;
            }
        }
        x--;
        ans += currentM;
        visited[ind] = true;
    }
    cout << ans << endl;
}
