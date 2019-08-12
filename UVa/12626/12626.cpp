#include <iostream>
#include <string.h>
using namespace std;

string s, comp = "MARGIT";
int T, vals[] = {1, 3, 2, 1, 1, 1};



int main(){
    scanf("%d", &T);
    getline(cin, s);
    while(T--){
        getline(cin, s);
        int arr[6], minAns = 10000000; //MARGIT
        for(int i = 0; i < 6; i++){
            arr[i] = 0;
        }
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < 6; j++){
                if(s[i] == comp[j]){
                    arr[j]++;
                    break;
                }
            }
        }
        for(int i = 0; i < 6; i++){
            minAns = min(minAns, arr[i]/vals[i]);
        }
        printf("%d\n", minAns);
    }
}
