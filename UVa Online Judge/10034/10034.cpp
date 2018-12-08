#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;

struct Point{
    double x;
    double y;
} points[105];

struct Path{
    int s;
    int e; //start end end indices;
    double len;
};

class pathCmp{
public:
    bool operator () (const Path &a, const Path &b) const{
        return a.len > b.len;
    }
};



int disjoint[105], n, T;
bool c = false;

double dist(int i, int j){
    return sqrt( (points[i].x - points[j].x) * (points[i].x - points[j].x) + (points[i].y - points[j].y) * (points[i].y - points[j].y) );
}


void correct(int ind){
    if(disjoint[ind] == ind){
        return;
    } else {
        correct(disjoint[ind]);
        disjoint[ind] = disjoint[disjoint[ind]];
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        priority_queue <Path, vector<Path>, pathCmp> que;
        for(int i = 0; i < n; i++){
            disjoint[i] = i;
            cin >> points[i].x >> points[i].y;
        }
        for(int i = 0 ; i < n; i++){
            for(int j = i + 1; j < n; j++){
                Path p;
                p.s = i;
                p.e = j;
                p.len = dist(i, j);
                //cout << "dist( " << i << ", " << j << ") = " << p.len << endl;
                que.push(p);
            }
        }
        double ans = 0;
        int currentDots = 0;
        while(!que.empty() && currentDots < n){
            Path p = que.top();
            //cout << "Chosen length: " << p.len << ": " << p.s << ", " << p.e << endl;
            que.pop();
            if(disjoint[p.s] != disjoint[p.e]){ //yes I want this one
                disjoint[disjoint[p.s]] = disjoint[p.e];
                //cout << p.s << " now has ancestor " << p.e << endl;
                for(int i = 0 ; i < n; i++){
                    correct(i);
                    //cout << i << " has correct ancestor " << disjoint[i] << endl;
                }
                currentDots++;
                ans += p.len;
            }
        }

        if(!c)
            c = true;
        else
            cout << endl;

        printf("%.2f\n", ans);

    }

}
