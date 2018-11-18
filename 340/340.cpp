#include <iostream>
using namespace std;


int len;

int main(){
    while(cin >> len){
        int ans[len];
        int guess[len];
        bool matcheda[len], matchedb[len];
        int a, b;
        for(int i = 0; i < len; i++){
            cin >> ans[i];
        }
        int clock = 0;
        while(cin >> guess[clock]){
            bool canGo = true;
            if(clock == len-1){ //run
                clock = 0;
                a = b = 0;

                for(int i = 0; i < len; i++){
                    matcheda[i] = false;
                    matchedb[i] = false;
                    if(guess[i] != 0){
                        continue;
                    } else if(i == len-1){
                        cout << "oh boi" << endl;
                        canGo = false;
                    }
                }
                if(canGo){
                    for(int i = 0; i < len; i++){
                        if(ans[i] == guess[i]){
                            a++;
                            cout << i << " match" << endl;
                            matcheda[i] = true;
                            matchedb[i] = true;
                        }
                    }
                    for(int i = 0; i < len; i++){
                        for(int j = 0; j < len; j++){
                            //cout << "Checking " << i << ", " << j << "  " << matched[i] <<  endl;
                            if(ans[i] == guess[j] && !matcheda[i] && matchedb[j]){
                                cout << i << " and " << j << " match" << endl;
                                b++;
                                matcheda[i] = true;
                                matchedb[j] = true;
                            }
                        }
                    }
                    cout << a << "  " << b << endl;
                }


            } else {
                clock++;
            }
        }
    }

}
