#include <iostream>
#include <map>
using namespace std;

const int M = 100000;
int c = 0, a, b, zeroes, ones;
map<int, int> indegs, dsu;
bool isGood = true;

void flat(int n){
    if(n == dsu[n]) return;
    flat(dsu[n]);
    dsu[n] = dsu[dsu[n]];
}


int main(){
    indegs.clear();
    zeroes = 0; ones = 0;
    isGood = true;
    while(cin >> a >> b){
        if((a < 0) && (b < 0)) return 0;
        if(!a && !b){ //calculate
            if(isGood){
                for(auto p : indegs){
                    if(p.second == 0) {
                        zeroes++;
                    } else if(p.second != 1) {
                        isGood = false;
                    }
                }
            }
            printf("Case %d", ++c);
            if(!indegs.size()){
                printf(" is a tree.\n");
            } else if(!isGood || zeroes != 1){
                printf(" is not a tree.\n");
            } else {
                printf(" is a tree.\n");
            }
            //output
            //
            isGood = true;
            zeroes = 0; ones = 0; indegs.clear();
            for(int i = 0; i < M; i++) dsu[i] = i;
        } else {
            if(!indegs.count(a)) indegs.insert({a, 0});
            if(!indegs.count(b)) indegs.insert({b, 0});
            if(!dsu.count(a)) dsu.insert({a, a});
            if(!dsu.count(b)) dsu.insert({b, b});
            indegs[b]++;
            flat(a);
            flat(b);
            if(dsu[a] == dsu[b]) isGood = false;
            if(a == b) isGood = false;
            dsu[a] = dsu[dsu[b]];
        }
    }
}
