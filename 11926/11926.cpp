#include <iostream>
using namespace std;

bool isFree[1000000 + 5];
int m, n, s, e, p;
bool isGood;
int main(){
    while(cin >> m >> n){
        if(m == 0 && n == 0) return 0;
        isGood = true;
        for(int i = 0; i< 1000000; i++){
            isFree[i] = true;
        }
        int counter = 0;
        for(int i = 0; i < m ; i++){
            cin >> s >> e;
            counter = 0;
            for(int j = s; j <= e; j++){
                if(isFree[j]){
                    isFree[j] = false;
                } else {

                    if(j != s && j != e){
                        isGood = false;

                        break;
                    } else {
                        counter++;
                        if(counter == 2){
                            isGood = false;
                        }
                    }
                    continue;

                }
            }
        }
        for(int i = 0; i < n; i++){
            cin >> s >> e >> p;
            for(int j = s; j < 1000000; j += p){
                counter = 0;
                for(int k = j; k <= j + e - s; k++){
                    if(isFree[k]){
                    isFree[k] = false;
                } else {
                    if(k != j && k != j + e - s){
                        isGood = false;

                        break;
                    } else {
                        counter++;
                        if(counter == 2) isGood = false;
                    }
                    continue;
                }
                }
            }
        }
        if(isGood){
            cout <<"NO CONFLICT" << endl;
        } else {
            cout << "CONFLICT" << endl;
        }
    }

}
