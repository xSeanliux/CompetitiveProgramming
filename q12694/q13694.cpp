#include <iostream>
using namespace std;

struct Meeting{
    int s, f;
    int status = 0; //0 for unused, 1 for using, 2 for declined.
};

Meeting meetings[25];

int main(){


    int cases;
    int j  =  0, counter = 0;
    while(cin >> cases){
        while(cases--){


                    while(cin >> meetings[j].s >> meetings[j].f){
                            if(meetings[j].s == 0 & meetings[j].f == 0){
                                break;
                            }
                            j++;

                    }
                        //end of test case; start calculating


                        for(int i = 0 ; i <= j; i++){ //sort, j is the length of the array.
                            for(int k = i + 1 ; k <= j; k++){
                                if(meetings[i].f > meetings[k].f){
                                    Meeting tmp = meetings[i];
                                    meetings[i] = meetings[k];
                                    meetings[k] = tmp;


                                }

                            }
                        }

                        //cout << "sorting" << endl;

                        int counter = 0, startline = 0;
                        for(int i = 0 ; i <= j ; i++){
                               if(meetings[i].s != 0 | meetings[i].f != 0){
                                    if(meetings[i].s >= startline){
                                       counter++;
                                       startline = meetings[i].f;
                                       meetings[i].status = 1;
                                    }
                               }




                        }
                        for(int i = 0; i <= j; i++){
                                //printf("After:  %d, %d, status: %d \n", meetings[i].s, meetings[i].f, meetings[i].status );

                        }
                        printf("%d\n", counter);
                        counter = 0;

                        //reset everithin
                        for(int i = 0 ; i <= j ; i++){
                            meetings[i].s = 0;
                            meetings[i].f = 0;
                            meetings[i].status = 0;
                        }





                }









}
}
