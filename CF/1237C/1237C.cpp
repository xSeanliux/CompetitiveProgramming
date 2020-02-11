#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct Point{
    int x, y, z, id;
    Point(){}
    Point(int X, int Y, int Z, int I): x(X), y(Y), z(Z), id(I){}
    bool operator<(const Point p) const {
        if(z == p.z){
            if(x == p.x){
                return y < p.y;
            }
            return x < p.x;
        }
        return z < p.z;
    }
};

int n, a, b, c;
vector<Point> vec;

int main(){
    ericxiao;
    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        vec[i] = Point(a, b, c, i + 1);
    }
    sort(vec.begin(), vec.end());
    vector<Point> pointsZ, pointsX, exPoint;
    exPoint.clear();
    int cz, cx;
    for(int i = 0; i < n; i++){
        cz = vec[i].z;
        pointsZ.clear();
        pointsX.clear();
        while(i < n && vec[i].z == cz){
            //cout << "Pushing " << vec[i].x << " " << vec[i].y << " " << vec[i].z << endl;
            pointsZ.push_back(vec[i++]);
        }
        i--;
        for(int j = 0; j < pointsZ.size(); j++){
            if(j < pointsZ.size() - 1 && pointsZ[j].x == pointsZ[j + 1].x){
                cout << pointsZ[j].id << " " << pointsZ[j + 1].id << endl;
                j++;
            } else {
                pointsX.push_back(pointsZ[j]);
                //cout << "X: Pushing " << pointsZ[j].x << " " << pointsZ[j].y << " " << pointsZ[j].z << endl;
            }
        }
        if(pointsX.size() > 1){
            for(int j = 0; j < pointsX.size() - 1; j += 2){
                cout << pointsX[j].id << " " << pointsX[j + 1].id << endl;
            }
        }

        if(pointsX.size() % 2) exPoint.push_back(*pointsX.rbegin());
    }
    for(int i = 0; i < exPoint.size(); i += 2){
        cout << exPoint[i].id << " " << exPoint[i + 1].id << endl;
    }
}
