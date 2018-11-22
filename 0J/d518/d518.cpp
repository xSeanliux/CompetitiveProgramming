#include <iostream>
#include <string.h>
#include <map>
using namespace std;

string s;

int N;

int main(){
    while(cin >> N){
        map <string, int> num;
        int K = 0;
        for(int i = 0; i < N; i++){
            cin >> s;
            if(num.count(s)){
                printf("Old! %d\n", num[s]);
            } else {
                printf("New! %d\n", ++K);
                num.insert(pair<string , int>(s, K));
            }
        }
    }
}
