#include <iostream>
#include <string.h>
#include <map>
using namespace std;

string s;
int N;

map<int, int> m;

int main(){
    while(cin >> s){
        if(s == "0") return 0;
        else N = stoi(s.substr(0, s.length()-1));
        m.clear();
        int arr[N + 1];
        for(int i = 0 ; i < N; i++){
            scanf("%d", &arr[i]);
            m.insert(pair<int, int>(arr[i], i));
        }
        bool hasArith = false;
        for(int i = 0; i < N && !hasArith; i++){
            for(int j = i + 1; j < N; j++){
                if(!((arr[i] + arr[j]) % 2)){
                    //cout << "Checking: " << arr[i] << " and " << arr[j] << endl;
                    int mid = (arr[i] + arr[j]) / 2;
                    if(m.count(mid) && m[mid] > i && m[mid] < j){
                        //cout << "found" << endl;
                        hasArith = true;
                        break;
                    }
                }
            }
        }
        if(!hasArith){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}
