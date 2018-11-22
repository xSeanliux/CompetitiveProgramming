#include <iostream>
using namespace std;
int ans[100];
int nums[105]; //max 105;
bool visited[105];
int lim = 0, N;
void dfs(int iteration, int lastIndex){
    if(iteration == lim){
        //if(!hasNoRepeats())return;
        for(int i = 0 ; i < lim ; i++){
            cout << ans[i] << " ";
            //visited[i] = false;
        }
        cout << endl;//visited[i] = false;
        return;

    }//visited[i] = false;

    for(int i = lastIndex; i < N; i++){
            if(!visited[i]){
                //cout << "Chosen " << nums[i] << endl;
                visited[i] = true;
                ans[iteration] = nums[i];
                dfs(iteration+1, i);
                visited[i] = false;
            }

    }
}

void qs(int arr[], int left, int right){
    if(left >= right) return;
    int pivot = arr[left];
    int left_counter = left;
    for(int i = left; i <= right; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[left_counter]);
            left_counter++;
        }


    }
    swap(arr[left], arr[left_counter-1]);
    qs(arr, left, left_counter-2);
    qs(arr, left_counter, right);
}

int main(){
    //int N;
    while(cin >> N){
        if(!N) return; //if N is 0
        for(int i = 0; i < N; i++){
            visited[i] = false;
        }
        for(int i = 0 ; i < N; i++){
            cin >> nums[i];
        }
        cin >> lim;
        qs(nums,0 , N-1);
        dfs(0, 0);

    }
}
