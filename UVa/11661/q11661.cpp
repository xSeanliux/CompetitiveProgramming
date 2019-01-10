#include <iostream>
#include <math.h>
using namespace std;
char road[2000005]; //road is smaller than 2e6.
int main(){
    int len, Rindex, Dindex;
    int dist = 2000005;
    while(cin >> len){

        if(len != 0){
            for(int i = 1 ; i <= len ; i++){
                cin >> road[i];

            }
            dist = 2000005;
            Rindex = -1;
            Dindex = -1;

            //code
            for(int i = 1 ; i <= len; i++){
                //dist = 2000005;
                if(road[i] == 'R' | road[i] == 'Z'){
                    //cout << "Found R at" << i << endl;
                    Rindex = i;
                    //cout << "abs(Rindex-Dindex)" << abs(Rindex-Dindex) << endl;

                    //if(abs(Rindex-Dindex) <= dist) dist = abs(Rindex-Dindex);
                    //cout << "dist is now" << dist << endl;
                }
                if(road[i] == 'D' | road[i] == 'Z'){
                    //cout << "Found D at "<< i << endl;
                    Dindex = i;
                    //cout << "abs(Rindex-Dindex)" << abs(Rindex-Dindex) << endl;

                    //cout << "dist is now" << dist << endl;
                }
                if(abs(Rindex-Dindex) <= dist & Dindex >= 0 & Rindex >= 0) dist = abs(Rindex-Dindex);
                //cout << dist << endl;

            }
            cout << dist << endl;

        } else {
            return 0 ;
        }


    }

}



