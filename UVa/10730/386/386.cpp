#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int cube, currentBest[3], now[3];
set <long long int> cubes;
map <long long int, int> croot;

struct Sol{
    long long int b, c, d;
};

bool solCmp(const Sol a, const Sol b){
    if(a.b == b.b)
        return a.c < b.c;
    return a.b < b.b;
}

vector <Sol> sols;



int main(){
    for(int i = 1; i <= 200; i++){
        cubes.insert(i*i*i);
        croot.insert(pair<int, int>(i*i*i, i));
    }
    currentBest[1] = 2147483647;
    for(int cube = 2; cube <= 200; cube++){
        sols.clear();
        for(long long int i = 2; i < cube; i++){ //get solutions
            for(long long int j = i; j < cube; j++){
                long long int res = cube*cube*cube - i*i*i - j*j*j;
                if(cubes.count(res) && res >= i*i*i && res <= j*j*j){
                    Sol s;
                    s.b = i;
                    s.c = croot[res];
                    s.d = j;
                    sols.push_back(s);
                }
            }
        }
        sort(sols.begin(), sols.end(), solCmp);
        int l = sols.size();
        for(int i = 0 ; i < l; i++){
            printf("Cube = %lld, Triple = (%lld,%lld,%lld)\n", cube, sols[i].b, sols[i].c, sols[i].d);
        }
        //output solution
    }
}
