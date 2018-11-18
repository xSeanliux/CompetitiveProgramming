#include <iostream>
using namespace std;
int sum, diff, a, b, N;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> sum >> diff;
        if(sum + diff == 0){
            a = b = 0;
        }else if(sum <= diff || (sum+diff)%2 == 1){
            a = -1;
        }else{
            a = (sum + diff)/2;
            b = sum - a;
        }
        cout << (a != -1 ? to_string(a) + " " + to_string(b) : "impossible") << endl;



    }


}
