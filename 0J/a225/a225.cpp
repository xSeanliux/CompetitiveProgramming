#include <iostream>
using namespace std;

bool largerThan(int a, int b){
    if(a%10 > b%10){
        return true;
    } else if (a % 10 < b % 10){
        return false;
    } else {
        if(a < b){
            return true;
        } else {
            return false;
        }
    }
}

int qs(int arr[], int left, int right)
{
    int pivot = arr[left];
    int left_counter = left;

    if(right <= left) return 0 ;




    for(int i = left; i <= right; i++)
    {

        if(!largerThan(arr[i], pivot))
        {


            swap(arr[i], arr[left_counter]);
            left_counter++;



        }
    }
    swap(arr[left], arr[left_counter-1]);






    qs(arr, left, left_counter-2);
    qs(arr, left_counter, right);



}




int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int arr[N];
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        qs(arr, 0, N-1);
        for(int i = 0 ; i < N ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

}
