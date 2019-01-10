#include <iostream>
#include <math.h>
#include <vector>
#define SWN 524291
#define MN 524288
using namespace std;

vector<bool> switches(2 * SWN + 2, false);
vector< vector<int> > ans;
int D, I, c;

int pows[] = {1, 2, 4 ,8 ,16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};

void getAns(){
    for(int i = 1 ; i <= MN; i++){ //roll MN balls, any more and it will return an error
        int loc = 1, layer = 1;
        while(layer <= 20){
            if(i <= pows[layer-1]){
                //printf("Layer %d in the no %d ball will fall in %d\n", layer, i, loc);
                ans[layer][i] = loc;
            }

            int oriLoc = loc;
            switches[loc] = !switches[loc];
            loc = switches[oriLoc] ? 2*oriLoc  : 2*oriLoc + 1;
            layer++;
        }
    }
}

int main(){
    ans.push_back(vector<int>(1));
    for(int i = 1; i <= 20; i++){
        ans.push_back(vector<int>(pows[i-1] + 1));
    }
    getAns();
    cin >> c;
    while(c--){
        cin >> D >> I;
        printf("%d\n", ans[D][I]);
    }
    cin >> c;
}
