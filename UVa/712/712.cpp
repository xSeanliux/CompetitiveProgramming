#include <iostream>
#include <string.h>
using namespace std;

int vars, queries, ct = 0;
string s, res, ques;
int main(){
    while(cin >> vars){
        int arr[vars], q[vars];
        if(!vars) return 0;
        for(int i = 0; i < vars; i++){
            cin >> s;
            int n = s[1] - '1';
            arr[n] = i;
        }
        cin >> res;
        cin >> queries;
        printf("S-Tree #%d:\n", ++ct);
        for(int i = 0; i < queries; i++){
            cin >> ques;
            for(int j = 0; j < vars; j++){
                q[ arr[j] ] = ques[j] - '0';
            }
            int val = 0;
            for(int j = 0; j < vars; j++){
                val += q[j];
                val *= 2;
            }
            cout << res[val/2];
        }
        printf("\n\n");
    }
}
