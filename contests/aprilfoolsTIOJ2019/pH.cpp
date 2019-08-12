#include <iostream>
#include <vector>
using namespace std;

int R = 123;//3185327

int rand(){
    return R = (R * 131231 + 123912031) % 256;
}

vector<int> vals = {42, 42, 0, 0, 255, 42};

string val = "aabba";

int main(){
    if(val.length() > 50) cout << val.substr(0, 50);
    else cout << val;
}
