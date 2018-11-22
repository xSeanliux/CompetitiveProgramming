#include <iostream>
using namespace std;

int nums[13 + 5]; //holding the set of lucky nums
int ans[6]; //holding the current ans
int k;
void dfs(int iteration){
    if(iteration == 6){
        for(int i = 0; i < 6; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    } else {
        for(int i = iteration; i < k; i++){
                if(iteration != 0){
                    if(nums[i] > ans[iteration - 1]){ //next num must be bigger than the previous one
                        ans[iteration] = nums[i];
                //cout << "Chosen" << nums[i] << ", will now run from " << i << endl;
                    dfs(iteration + 1);
                    }

                } else {

                ans[iteration] = nums[i];
                //cout << "Chosen" << nums[i] << ", will now run from " << i << endl;
                dfs(iteration + 1);
                }





        }
    }

}

int main(){
    //int k;
    while(cin >> k){
        if(k > 0){
            for(int i = 0; i < k; i++){
                cin >> nums[i];

                //visited[i] = false;
            }
            dfs(0);
        } else {
            return 0;
        }
    }

}
