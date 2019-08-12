#include <iostream>
#include <queue>
using namespace std;

int T, N;
char colour, c, mp[1005][1005];
int A, B;

struct Col{
    char c;
    int y, x;
    Col(){}
    Col(char c, int y, int x): c(c), y(y), x(x){}
} cols;

bool hasColour(char c, char nc){
    if(c == nc) return true;
    if(c == 'R'){
        return (nc == 'O' || nc == 'P' || nc == 'D');
    } else if(c == 'Y'){
        return (nc == 'O' || nc == 'D' || nc == 'G');
    } else if(c == 'B'){
        return (nc == 'P' || nc == 'D' || nc == 'G');
    }
}

struct Obj{
    char c;
    int y, x, it;
    Obj(){}
    Obj(char c, int y, int x, int it): c(c), y(y), x(x), it(it){}
    Obj(Col col, int it): c(col.c), y(col.y), x(col.y), it(it){}
};

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                mp[i][j] = ' '; //white space
            }
        }
        for(int i = 0; i < 3; i++){
            cin >> c >> x >> y;
            cols[i] = Col(c, y, x);
        }
        cin >> colour;
        int ans = (colour == 'R' || colour == 'Y' || colour == 'B');
        int currentIt = 0;
        queue<Obj> qu;
        int currentInteration = 0;
        qu.push(Obj(cols[0], 0));
        qu.push(Obj(cols[1], 0));
        qu.push(Obj(cols[2], 0));
        while(!qu.empty()){
            if()
        }
    }
}
