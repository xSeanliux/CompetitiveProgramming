#include <iostream>
using namespace std;


float rectangles[15][5]; //no more than 10 rectangles, and four coords for the points (0~4), using 1~4
int main(){
    float x, y; char _tmp;
    int counter = 1, pointcounter = 0, containscounter;
    while(cin.peek() != '*'){//gets all the rectangles

            cin >> _tmp >> rectangles[counter][1] >> rectangles[counter][2] >> rectangles[counter][3] >> rectangles[counter][4];
            //cout << rectangles[i][1]<<"  " << rectangles[i][2]<<"  "<< rectangles[i][3]<<"  "<< rectangles[i][4] << endl;
            counter++;
    }
    cin >> _tmp; //just removes the asterisk
    while(cin >> x >> y){ //rectangle is (x1, y1), (x2, y2)
        pointcounter++;
        containscounter = 0;
        for(int i = 0 ; i < counter; i++){
            if(x > rectangles[i][1] & x < rectangles[i][3] & y > rectangles[i][2] & y > rectangles[i][4]){
                printf("Point %d is contained in figure %d\n", pointcounter, i);
                containscounter++;
            }
        }
        if(containscounter == 0) printf("Point %d is not contained in any figure. \n");
    }
    cout << "OK" << endl;




}
