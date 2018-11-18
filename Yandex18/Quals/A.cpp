#include <iostream>
#include <algorithm>
using namespace std;
int ans[10 + 5];
int guess[6 + 5];
int c;

int main(){
    for(int i = 0 ; i < 10; i++){
        cin >> ans[i];
    }
    sort(ans, ans + 10);
    /*
    for(int i = 0 ; i < 10; i++){
        cout << ans[i] << " ";

    }
    */
    cin >> c;
    for(int k = 0; k < c; k++){
        for(int i = 0 ; i < 6; i++){
            cin >> guess[i];
        }
        sort(guess, guess + 6);
        int current = 0;
        for(int i = 0 ; i < 10; i++){
            for(int j = 0; j < 6; j++){
                if(ans[i] == guess[j]) current++;
            }
        }
        if(current >= 3){
            printf("Lucky\n");
        } else {
            //cout << "C: " << current << endl;
            printf("Unlucky\n");
        }
    }
}
