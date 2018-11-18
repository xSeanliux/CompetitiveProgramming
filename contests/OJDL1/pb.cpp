#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
long long int l, n;
bool arr[10000000];
int ans[10000000];

int main(){
    cin >> l >> n;
    for(int i = 0 ; i < l; i++){
        scanf("%d", &arr[i]);
    }
    int counter = 0, ava = n, mA = 0;
    for(int i = 0 ; i < l; i++){
        if(!ans[i]){
            //cout << "Checking i = " << i<< endl;
            counter = 0;
            ava = n;
            bool flag = true;
            for(int j = i ; j < l && flag; j++){
                //cout << "Checking j = " << j << endl;

                if(!ava && !arr[j]){
                    ans[i] = counter;
                    flag = false;
                    break;
                }
                counter++;
                if(!arr[j]){
                    ava--;
                }
            }
            //cout << "counter = " << counter << endl;
            ans[i] = counter;
            //cout << "ans[" << i << "] = " << ans[i] << ", counter = " << counter << endl;
            if(mA < ans[i]) mA = ans[i];
            //cout << "ans[" << i << "] = " << ans[i] << endl;
            bool flag2 = true;
            for(int j = i + 1 ; j < l && flag2; j++){
                if(!arr[j]){
                    for(int k = j; k < l; k++){
                        if(arr[k]){
                            i = k-1;
                            //cout << "k = " << k << endl;
                            flag2 = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << mA << endl;
}
