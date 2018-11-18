#include <iostream>
using namespace std;

int width, N;
long long int tA;
int wi, li;

int main(){
    while(cin >> width >> N){
        tA = 0;
        for(int i = 0 ; i < N ; i++){
            cin >> wi >> li;
            tA += wi * li;
        }
        printf("%lld\n", tA/width);
    }

}
