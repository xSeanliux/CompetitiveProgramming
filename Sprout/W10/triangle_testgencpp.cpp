#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

long long int R = 7123;
long long int Rand(){
    return R = ((R * R + 69) % 0xdefaced);
}

set<pair<int, int> > edges;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << 447 << " " << 447 * 446/2 << endl;
    for(int i = 0; i < 447; i++){
        for(int j = i + 1; j < 447; j++){
            cout << i << " " << j << endl;
        }
    }
}
