#include <iostream>
#include <math.h>
#include <string.h>
#include <map>
#define PI  3.141592653589793
#define R 6378
using namespace std;

struct Coord{
    double theta;
    double phi;
};

map <string , Coord > locations;

string s, c1, c2;
double theta, phi;

int main(){
    while(cin >> s){
        if(s == "#") break;
        cin >> theta >> phi;
        theta *= PI/180; //convert to radian
        phi *= PI/180;
        Coord c;
        c.theta = theta;
        c.phi = phi;
        locations.insert(pair<string, Coord >(s, c));
    }
    while(cin >> c1){
        if(c1 == "#") break;
        cin >> c2;
        cout << c1 << " - " << c2 << endl;
        if(!locations.count(c1) || !locations.count(c2)){
            cout << "Unknown" << endl;
            continue;
        }
        Coord co1 = locations[c1];
        Coord co2 = locations[c2];
        double d = R * sqrt(  2 - 2*cos(co1.theta)*cos(co2.theta)*cos(co1.phi - co2.phi) - 2*sin(co1.theta)*sin(co2.theta)  );
        double ans = 2*R*asin(d/2/R);
        if(ans != ans) //check if nan
            printf("0 km\n");
        else
            printf("%.0f km\n", 2*R*asin(d/2/R));
        //cout << "d = " << d << endl;


    }
}
