#include <iostream>
using namespace std;

void qs(int arr[], int left, int right){
    int pivot = arr[left];
    int left_counter = left;
    if(left >= right) return;
    for(int i = left ; i <= right; i++){
        if(arr[i] <= pivot){
            swap(arr[left_counter], arr[i]);
            left_counter++;

        }
    }
    swap(arr[left], arr[left_counter-1]);
    qs(arr, left, left_counter-2);
    qs(arr, left_counter, right);

}




int main(){
    int N, Q, counter = 1;
    while(cin >> N >> Q){

        if(N == 0 && Q == 0){
            break;
        }
        else {

            int marbles[N];
            for(int i = 0 ; i < N ; i++){
                cin >> marbles[i];
                //cout << "Recieved: " << marbles[i] << endl;
            }
            int questions[Q];
            for(int i = 0 ; i < Q; i++){
                cin >> questions[i];
            }
            qs(marbles, 0, N-1);
            printf("CASE# %d:\n",counter);
            for(int i = 0 ; i < Q; i++){//scanning thru every question
                for(int j = 0; j < N ; j++){
                    if(marbles[j] == questions[i]){
                        printf("%d found at %d\n", questions[i], j+1);
                        break;
                    } else if(j == N-1){
                        printf("%d not found\n", questions[i]);
                        break;
                    }
                }
            }

        }
        counter++;

    }

}
