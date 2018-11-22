#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int nStrings;
bool canDo = true;

bool isSubstr(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    int lA = a.length();
    int lB = b.length();
    for(int i = 0 ; i < lA - lB + 1; i++){
        for(int j = 0; j < lB; j++){
            if(a[i + j] != b[j]){
                //cout << "a[" << i + j << "] != b[" << j << "]" << endl;
                break;
            } else {
                if(j == lB-1){
                    return true;
                }
            }
        }
    }
    return false;
}

bool cmp(const string a, const string b){
    return a.length() < b.length();
}


int main(){
    cin >> nStrings;
    string arr[nStrings];
    for(int i = 0 ; i < nStrings; i++){
        cin >> arr[i];
    }
    sort(arr, arr + nStrings, cmp);
    for(int i = 0 ; i < nStrings - 1 && canDo; i++){
        if(arr[i].length() == arr[i+1].length()){
            if(arr[i] != arr[i+1]){
                //cout << "A" << endl;
                canDo = false;
            }
        } else {
            if(!isSubstr(arr[i], arr[i+1])){
                //cout << "B: " << arr[i] << ", " << arr[i+1] << endl;
                canDo = false;
            }
        }
    }
    if(canDo){
        cout << "YES" << endl;
        for(int i = 0 ; i < nStrings; i++){
            cout << arr[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}
