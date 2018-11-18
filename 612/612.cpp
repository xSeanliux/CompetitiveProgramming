#include <iostream>
using namespace std;


int cases, len, entries;
struct DNA{
    int len;
    char gene[100];
    int chaoticity;

};

DNA arr[100 + 5];

void getChaoticity(DNA *d){
    d->chaoticity = 0;
    for(int i = 0; i < d->len-1; i++){
        int t = 0;
        for(int k = i+1; k < d->len; k++){
            if(d->gene[k] >= d->gene[i]) break;
            t = k - i;
        }
        //cout << t << endl;
        d->chaoticity += t;
    }
}

void sortDNA(int left, int right){
    if(left >= right) return;
    DNA pivot = arr[left];
    int left_counter = left;
    for(int i = left; i < right; i++){
        if(arr[i].chaoticity <= pivot.chaoticity){
            if(arr[i].chaoticity < pivot.chaoticity){
                swap(arr[i], arr[left_counter]);
            }left_counter++;
        }
    }
    swap(arr[left], arr[left_counter-1]);
    sortDNA(left, left_counter-2);
    sortDNA(left_counter, right);

}

int main(){
    while(cin >> cases){
        for(int i = 0; i < cases; i++){
            cin >> len >> entries;
            for(int j = 0 ; j < entries; j++){

                for(int k = 0; k < len; k++){
                    cin >> arr[j].gene[k];
                }
                arr[j].len = len;
                getChaoticity(&arr[j]);

            }
            sortDNA(0, entries);
            //cout << "b" << endl;
            for(int m = 0; m < entries; m++){

                cout << arr[m].gene << " "<<arr[m].chaoticity<<  endl;
            }

        }
    }
}
