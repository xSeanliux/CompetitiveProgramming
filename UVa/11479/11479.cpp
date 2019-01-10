#include <iostream>
#include <algorithm>
using namespace std;

long long int sides[3];
int c;
int main(){
    cin >> c;
    for(int ia = 1; ia <= c; ia++){
        //if(ia > 1) cout << endl;
        cin >> sides[0] >> sides[1] >> sides[2];
        printf("Case %d: ", ia);
        sort(sides, sides+3);
        if(sides[0] <= 0){
            printf("Invalid\n");
            continue;
        }
        if(sides[2] >= sides[0] + sides[1]){
            printf("Invalid\n");
        } else if(sides[0] == sides[1] || sides[1] == sides[2]){
            if(sides[0] == sides[2]){
                printf("Equilateral\n");
            } else {
                printf("Isosceles\n");
            }
        } else {
            printf("Scalene\n");
        }
        //cout << endl;
    }

}
