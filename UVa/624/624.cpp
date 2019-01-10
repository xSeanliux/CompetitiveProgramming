#include <iostream>
using namespace std;


int len, tracks;
int tracksarr[100000];
int timearr[100000];
int ansarr[100000];
int main(){
    while(cin >> len >> tracks){
        for(int i = 0; i < tracks; i++){
            cin >> tracksarr[i];
        }
        for(int i =  0; i < tracks; i++){
            for(int j = tracksarr[tracks-1]; j >= tracksarr[i]; j--){
                if(timearr[j - tracksarr[i]] + tracksarr[i] > timearr[j]){
                    timearr[j] = timearr[j - tracksarr[i]] + tracksarr[i];
                }
            }
        }
        cout << timearr[len] << endl;
    }

}
