#include <iostream>
using namespace std;

long long int m, n, maxCap, c = 0;
long long int currentUse, maxUse;
long long int aps[100000], ins[100000];
bool isOn[1000000], isSafe;
int main(){
    c = 0;
    while(cin >> m >> n >> maxCap){
        //cout << "got " << m << " " << n << endl;
        if(!m && !n && !maxCap) return 0;
        else{
            for(int i = 0; i < m; i++){
                cin >> aps[i];
            }
            for(int i = 0; i < n; i++){
                cin >> ins[i];
                isOn[i] = false;
            }

            isSafe = true;
            currentUse = 0;
            maxUse = 0;
            for(int i = 0 ; i < n; i++){
                currentUse += (isOn[ins[i] - 1] * -2 + 1)*aps[ins[i] - 1]; //maps 0 to 1 and 1 to -1;
                //cout << "Adding : " << (isOn[ins[i] - 1] * -2 + 1) << endl;
                isOn[ins[i] - 1] = !isOn[ins[i] - 1];
                if(currentUse > maxCap){
                    isSafe = false;
                }
                if(currentUse > maxUse)
                    maxUse = currentUse;
                //cout << "Current Usage: " << currentUse << endl;
            }
            printf("Sequence %lld\n", ++c);
            if(isSafe){
                printf("Fuse was not blown.\nMaximal power consumption was %lld amperes.", maxUse);
            } else {
                printf("Fuse was blown.");
            }
            printf("\n\n");
        }
    }
}
