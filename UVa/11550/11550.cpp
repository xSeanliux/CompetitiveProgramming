#include <iostream>
#include <set>
#include <utility>
using namespace std;

int T, H, W;

int main(){
    cin >> T;
    while(T--){
        cin >> H >> W;
        bool arr[H][W];
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> arr[i][j];
            }
        }
        bool isGood = true;
        set<pair<int, int> > s;
        for(int i = 0; i < W && isGood; i++){
            int sum = 0;
            pair<int, int> p;
            for(int j = 0; j < H; j++){
                if(arr[j][i]){
                    if(sum == 0){
                        p.first = j;
                    } else if(sum == 1){
                        p.second = j;
                        if(s.count(p)){
                            isGood = false;
                            break;
                        }
                        s.insert(p);
                    } else {
                        isGood = false;
                        break;
                    }
                    sum++;
                }
            }
            if(sum < 2) isGood = false;
        }
        cout << ((isGood) ? "Yes" : "No") << endl;
    }
}
