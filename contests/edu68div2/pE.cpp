#include <iostream>
#include <utility>
#include <math.h>
#include <vector>
using namespace std;

struct Line{
    bool ori; //0|, 1 -
    int l, r;
    Line(){}
    Line(bool ori, int l, int r): ori(ori), l(l), r(r){
        if(l > r){
            swap(l, r);
        }
    }
};

const int blockSize = 500;
int N, x, y;
vector<Line> hor, ver;

int main(){
    cin >> N;
    while(N--){
        cin >> x >> y;

    }
}
