#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, x, y;
char c;

struct Vec{
    long long int x, y;
    Vec(int x, int y): x(x), y(y){}
    Vec() {}
};

int cross(Vec a, Vec b){
    return a.x * b.y - a.y * b.x;
}

int dot(Vec a, Vec b){
    return a.x * b.x + a.y * b.y;
}

double len(Vec a){
    return sqrt((unsigned long long int)(abs(a.x))*(unsigned long long int)(abs(a.x)) + (unsigned long long int)(abs(a.y))*(unsigned long long int)(abs(a.y)));
}

double veccos(Vec a){
    //cout << "LEN (" << a.x << ", " << a.y << ") = " << len(a) << endl;
    return (dot(a, Vec(1, 0))+0.0)/len(a);
}

bool cmp(Vec a, Vec b){
    if(a.x == 0 && b.x == 0) return len(a) > len(b);
    else if(a.y == 0 && b.y == 0) return len(a) < len(b);
    return veccos(a) > veccos(b);
}

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        Vec cS = Vec(2000000000, 2000000000), st = Vec(2000000000, 2000000000), v; //INF
        int ind = 0;
        vector <Vec> vecs;
        for(int i = 0; i < N; i++){
            cin >> v.x >> v.y >> c;
            if(c == 'Y'){
                if(cS.y > v.y || (cS.y == v.y && cS.x > v.x)){
                    cS = v;
                    ind = vecs.size();
                }
                if(v.x < st.x || (v.x == st.x && v.y < st.y)){
                    st = v;
                }
                vecs.push_back(v);
            }
        }
        swap(vecs[ind], vecs[0]);
        for(int i = 0; i < vecs.size(); i++){
            vecs[i].x -= cS.x;
            vecs[i].y -= cS.y;
        }
        sort(vecs.begin() + 1, vecs.end(), cmp);
        for(int i = 0; i < vecs.size(); i++){
            vecs[i].x += cS.x;
            vecs[i].y += cS.y;
        }
        /*
        for(int i = 0; i < vecs.size(); i++){
            printf("%d %d cos theta = %f\n", vecs[i].x, vecs[i].y, veccos(vecs[i]));
        }
        */
        int index = 0;
        while(vecs[index].x != st.x || vecs[index].y != st.y) index++;
        printf("%d\n", vecs.size());
        for(int i = 0; i < vecs.size(); i++){
            printf("%d %d\n", vecs[ (index + i) % vecs.size() ].x, vecs[ (index + i) % vecs.size() ].y);
        }
    }
}
