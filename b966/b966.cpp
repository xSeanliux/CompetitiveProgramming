#include <iostream>
using namespace std;
int lengths[10004][2]; //storing all the lengths
void sortByStart(int left, int right){
    if(left >= right) return;
    int pivot = lengths[left][0];
    //cout << pivot << endl;
    int leftcounter = left;
    for(int i = left; i <= right ;i++){
        if(lengths[i][0] <= pivot){
            swap(lengths[i], lengths[leftcounter]);
            leftcounter++;
        }


    }
    swap(lengths[left], lengths[leftcounter-1]);
    sortByStart(left, leftcounter-2);
    sortByStart(leftcounter, right);



}


int main(){
    int N;

    while (scanf("%d", &N) != EOF){

        for(int i = 0 ; i < N; i++){
            scanf("%d %d", &lengths[i][0], &lengths[i][1]);
        }
        sortByStart(0, N-1);

        for(int i = 1 ; i < N; i++){
            if(lengths[i-1][1] >= lengths[i][0]){ //if the last entry is overlapping or touching the current one
                    int _min = min(lengths[i-1][0], lengths[i][0]);
                    int _max = max(lengths[i-1][1], lengths[i][1]);

                    //lengths[i-1][0] = _min;
                    //lengths[i-1][1] = _max;
                    lengths[i-1][0] = 0;
                    lengths[i-1][1] = 0;
                    lengths[i][0] = _min;
                    lengths[i][1] = _max;


            }
        }
        /*
        for(int i = 0 ; i < N ; i++){
            //cout << lengths[i][0] <<" " << lengths[i][1] << ", " << endl;
        }
        */
        int sum = 0;
        for(int i = 0 ; i < N ; i++){
            sum += lengths[i][1] - lengths[i][0];
        }
        cout << sum << endl;


    }
}
