#include <iostream>
using namespace std;
int cases, products, people;
int maxVal[35];
int weights[10000];
int value[10000];
long long int sum;

int main(){
    cin >> cases;
    for(int kk = 0; kk < cases; kk++){
        cin >> products;
        for(int i = 0; i < products; i++){
            cin >> value[i] >> weights[i];
        }
        for(int i = 0;i < 34; i++){
            maxVal[i] = 0;
        }
        for(int i = 0; i < products; i++){
            for(int j = 34; j >= weights[i]; j--){
                if(maxVal[j - weights[i]] + value[i] > maxVal[j] ){
                    maxVal[j] = maxVal[j - weights[i]] + value[i];
                }
            }
        }
        sum = 0;
        cin >> people;
        int mw;
        for(int i = 0; i < people; i++){
            cin >> mw;
            sum += maxVal[mw];
        }
        cout << sum << endl;
    }

}
