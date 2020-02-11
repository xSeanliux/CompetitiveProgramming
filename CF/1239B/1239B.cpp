#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

string s;
int n;
vector<int> presum;

int main(){
    cin >> n >> s;
    presum.resize(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') sum++;
        if(s[i] == ')') sum--;
        presum[i] = sum;
        cout << presum[i] << " ";
    }

}
