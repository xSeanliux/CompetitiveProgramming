#include <iostream>
using namespace std;

int cases, days, parties;
int partydays[1000];
bool canWork[3700];

int main(){
    cin >> cases;
    for(int fds = 0; fds < cases; fds++){
        cin >> days >> parties;
        for(int i = 1; i <= days; i++){
            canWork[i] = true;
        }
        int period;
        for(int i = 0; i < parties ; i++){
            cin >> period;
            for(int j = period; j <= days; j += period){
                if((j+1) % 7 > 1){
                    canWork[j] = false;
                }
            }
        }
        int sum = 0;
        for(int i = 1; i <= days; i++){
            sum += (canWork[i]) ? 0 : 1;
        }
        cout << sum << endl;
    }
}
