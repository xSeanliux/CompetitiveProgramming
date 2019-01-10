#include <iostream>
using namespace std;

int L, N;
char ans[81];

int dfs(int gen){
    if(gen == L-1){
        for(int i = 0; ans[i] != '\0'; i++) cout << ans[i];
        return 0;
    } else {
        for(int i = 0; i < L; i++){
            ans[gen] = i + 'A';
            bool flag = true;
            for(int j = 1; 2*j <= gen && flag; j++){ //check string of len j
                bool isOk = true;
                for(int k = 0; k < j; k++){
                    if(ans[gen - k - 1] == ans[gen - j - k - 1] && k == j-1){
                        isOk = false;
                        break;
                    }
                }
                if(!isOk){
                    flag = false;
                    break;
                }
            }
            if(flag){
                dfs(gen + 1);
            }
        }
    }
}


int main(){
    while(cin >> L >> N){
        if(!(L | N)) return 0;
        for(int i = 0; i < 80; i++) ans[i] = '\0';
        dfs(0);
    }
}
