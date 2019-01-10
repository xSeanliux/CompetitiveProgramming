#include <iostream>
using namespace std;


int N;
int arr[20], c;

int main(){
    long long int m;
    c = 1;
    while(cin >> N){

        m = 0;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        long long int p;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                p = 1;
                for(int k = i; k <= j; k++){
                    p *= arr[k];
                }
                //printf("%d to %d: %lld\n", i, j, p);
                if(p > m){
                    m = p;
                    //cout << "new m: " << m << endl;
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", c, m);
        c++;
    }

}
