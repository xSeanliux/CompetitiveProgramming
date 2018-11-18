#include <iostream>
#include
using namespace std;

int N;
int arr[100 + 5][100 + 5];
int current[2*100 + 5][100 + 5];
struct Num{
    int val;
    int head;
    int places[2][2];
};


Num vals[100*100 + 69];

int main(){
    for(int i = 0 ; i < 100 * 100 + 1; i++){
        vals[i].val = i;
    }
    cin >> N;
    for(int i = 0 ; i < 2*N; i++){
        for(int j = 0; j < N; j++){
            cin >> current[i][j];
            vals[current[i][j]].places[vals[current[i][j]].head] = j;
            vals[current[i][j]].head++;
        }
    }
    //search for the ones that are in place 1, k

}
