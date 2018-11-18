#include <iostream>
#include <algorithm>
using namespace std;


long long int n, m, currentHead, ans;
int heads[20000 + 5];
int knights[20000 + 5];

int main(){
    while(cin >> n >> m){
        if(!n && !m) return 0;
        for(int i = 0 ; i < n; i++){
            cin >> heads[i];
        }
        for(int i = 0 ; i < m; i++){
            cin >> knights[i];
        }
        if(m < n){
            printf("Loowater is doomed!\n");
            continue;
        }
        currentHead = 0, ans = 0;
        sort(heads, heads + n);
        sort(knights, knights + m);
        for(int i = 0 ; i < m; i++){
            if(heads[currentHead] <= knights[i]){
                //cout << "Slayed the " << currentHead << "th Hydra" << endl;
                currentHead++;
                ans += knights[i];
                if(currentHead == n)
                    break;

            }
        }
        if(currentHead < n){
            printf("Loowater is doomed!\n");
        } else {
            printf("%lld\n", ans);
        }
    }
}
