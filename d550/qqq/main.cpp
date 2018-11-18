#include <iostream>
using namespace std;
int arr[10000 + 5][200 + 5];
int N, M;
bool largerThan(int a[], int b[], int len){
    for(int i = 0; i < len; i++){
        if(a[i] > b[i]){
            return true;
        } else if(a[i] < b[i]) {
            return false;
        }
    }
    return true;
}

void qs(int left, int right, int len)
{
    int pivot[len];
    int a;
    for(int i = 0; i < len; i++){
        pivot[i] = arr[left][i];
    }

    int left_counter = left;

    if(right <= left) return;

    //cout << "i" << endl;


    for(int i = left; i <= right; i++)
    {
    //    cout << i << endl;
        if(!largerThan(arr[i], pivot, len))
        {

            for(int j = 0 ; j < len; j++){
                a = arr[i][j];
                arr[i][j] = arr[left_counter][j];
                arr[left_counter][j] = a;
            }
            //swap(arr[i], arr[left_counter]);
            left_counter++;



        }
    }
    //swap(arr[left], arr[left_counter-1]);
    for(int j = 0 ; j < len; j++){
        a = arr[left][j];
        arr[left][j] = arr[left_counter-1][j];
        arr[left_counter-1][j] = a;
    }






    qs(left, left_counter-2, len);
    qs(left_counter, right, len);



}

int main(){
    while(cin >> N >> M){
        for(int i = 0;  i < N; i++){
            for(int j = 0 ; j < M; j++){
                cin >> arr[i][j];
            }
        }

        qs(0, N-1, M);
        for(int i = 0;  i < N; i++){
            for(int j = 0 ; j < M; j++){
                cin >> arr[i][j];
            }
            cout << endl;
        }
    }
}
