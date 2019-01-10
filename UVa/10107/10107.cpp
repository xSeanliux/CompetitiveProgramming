#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec;
int N;

int main(){
    vec.clear();
    while(cin >> N){
        vec.push_back(N);
        sort(vec.begin(), vec.end());
        if(vec.size() % 2){
            cout << vec[(vec.size() - 1) / 2] << endl;
        } else {
            cout << ( vec[vec.size()/2] + vec[vec.size()/2 - 1] ) / 2 << endl;
        }
    }
}
