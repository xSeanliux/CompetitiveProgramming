#include <iostream>
using namespace std;
int N, c;
int has[12], need[12];

int main(){
    c = 1;
    while(cin >> N){
        if(N < 0) return 0;
        int sum = N;
        printf("Case %d:\n", c);
        for(int i = 0; i < 12; i++){
            cin >> has[i];
        }
        for(int i = 0; i < 12; i++){
            cin >> need[i];
        }
        for(int i = 0; i < 12; i++){
            cout << "No problem";
            if(sum >= need[i]){
                sum -= need[i];
                cout << "! :D" << endl;
            } else {
                cout << ". :(" << endl;
            }
            sum += has[i];
        }
        c++;
    }
}
