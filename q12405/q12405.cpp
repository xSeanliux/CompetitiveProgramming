#include <iostream>
#include <math.h>
using namespace std;
//double rectangles[11][4]; //no more than 10 rectangles, and then four coordinates for each one;
char farm[100];
bool contains(char c, int len){
    for(int i = 0 ; i < len; i++){
        if(farm[i] == c) return true;
    }
    return false;
}


int main(){
    int N;
    int len;
    //char farm[100];
    int counter;
    while(cin >> N){
        for(int i = 0 ; i < N; i++){
            counter = 0;
            cin >> len;
            for(int i = 0 ; i < len ; i++){
                cin >> farm[i]; //gets all the farmland into the char string
            }

            while(contains('.', len)){ //while dots are found, which means there are still farms which are unprotected
                for(int i = 0 ; i < len; i++){
                    if(farm[i] == '.'){
                        farm[i] = '#';
                        farm[i+1] = '#';
                        farm[i+2] = '#';
                        counter++;
                    }
                    for(int j = 0 ; j < len; j++){
                            //cout << farm[j];

                    }
                    //cout << endl;
                }
            }
            printf("Case %d: %d\n", i+1, counter);
        }

    }


}








