#include <iostream>
using namespace std;

int arr[105][105];
int sumArr[105][105];
int N;

int kruskal(int a[]){ //height N;
    int currentSum = 0, minSum = a[0];
    for(int i = 0; i < N; i++){
        if(a[i] > 0){
            currentSum += a[i];
        } else if(a[i] < 0){
            if(currentSum > minSum) minSum = currentSum;
            currentSum = 0;
            continue;

        }
    }
    return minSum;

}


int main(){
    cin >> N;
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            sumArr[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    int minsum = 0;
    for(int i = 0; i < N; i++){
        sum = 0;
        for(int j = 0; j < N; j++){
            sum += arr[i][j];
            sumArr[i][j+1] = sum;
            minsum += arr[i][j];
        }
    }
    cout << "msum " << minsum << endl << endl;
    for(int i = 0; i < N; i++){
        cout << endl;
        for(int j = 0; j <= N; j++){
            cout << sumArr[i][j] << " ";
        }
    }
    int tempArr[N];
    for(int i = 0; i <= N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = 0; k < N; k++){
                tempArr[k] = sumArr[k][j] - sumArr[k][i-1];
            }
            cout << endl << "KRUSKAL(" << i << ", " << j << "): " << kruskal(tempArr);
            if(minsum <= kruskal(tempArr)){
                //cout << "HEY" << i << ' ' << j << endl;
                minsum = kruskal(tempArr);
            }
        }
    }
    cout << minsum << endl;


}
