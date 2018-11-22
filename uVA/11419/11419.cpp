#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int H[1000 + 5], V[1000 + 5];
int h, v, m, n, nc, cX, cY;

int main(){
    while(cin >> m >> n >> nc){
        if(!m && !n && !nc) return 0;
        h = 0, v = 0;
        else {
            for(int ik = 0 ; ik  < nc; ik++){
                cin >> cX >> cY;
                if(!V[cX]) h++;
                if(!H[cY]) v++;
                V[cX]++;
                H[cY]++;
            }
        }
    }
}
