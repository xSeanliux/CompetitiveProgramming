#include <iostream>
using namespace std;

/*
000 W
100 R
010 Y
001 B
011 G
101 P
110 O
111 B
*/

struct Obj{
    int x, y, time;
    char c;
    Obj(){}
    Obj(int x, int y, int col, int time):x(x), y(y), c(col), time(time){}
    void print(){
        cout << "(" << x << ", " << y << "): " << c << endl;
    }
};


Obj q[(int)1e6];
int head = -1, tail = -1;

inline void push(Obj o){
    if(head == -1) head = 0;
    tail = (tail + 1) % (int)1e6;
    q[tail] = o;
}

inline Obj pop(){
    Obj o = q[head];
    if(head == tail){
        head = -1; tail = -1;
    } else {
        head = (head + 1) % (int)1e6;
    }
    return o;
}



int getCol(char c){
    if(c == 'R'){
        return 0b100;
    } else if(c == 'Y'){
        return 0b010;
    } else if(c == 'B'){
        return 0b001;
    } else if(c == 'G'){
        return 0b011;
    } else if(c == 'P'){
        return 0b101;
    } else if(c == 'O'){
        return 0b110;
    } else if(c == 'B'){
        return 0b111;
    } else {
        return 0;
    }
}

int N;
int mp[(int)1e3 + 10][(int)1e3 + 10];
int dirs[8][2] = {{-1, -1}, {0, -1},{1, -1},{-1, 0},{1, 0},{-1, 1},{0, 1}, {1, 1}};
bool yvis[(int)1e3 + 10][(int)1e3 + 10], rvis[(int)1e3 + 10][(int)1e3 + 10], bvis[(int)1e3 + 10][(int)1e3 + 10];
int main(){
    int Tt;
    cin >> Tt;
    //cout << "TT = " << Tt << endl;
    for(int zz = 0; zz < Tt; zz++){
        cin >> N;
        head = -1, tail = -1;
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                mp[i][j] = 0;
                rvis[i][j] = 0;
                yvis[i][j] = 0;
                bvis[i][j] = 0;
            }
        }
        char c, _t;
        int x, y, tgt;
        for(int i = 0; i < 3; i++){
            cin >> c >> x >> y;
            if(c == 'Y'){
                yvis[x][y] = true;
            } else if(c == 'R'){
                rvis[x][y] = true;
            } else if(c == 'B'){
                bvis[x][y] = true;
            }
            push(Obj(x, y, c, 0));
            //q[head].print();
        }

        cin >> _t; tgt = getCol(_t);
        int maxAns = 0, currentAns = 0, currentTime = 0, cnt = 0;
        while(head != -1){
            Obj t = pop();
            cnt++;
            if(currentTime + 1 == t.time){
                maxAns = max(maxAns, currentAns);
                currentTime++;
                //cout << "t = " << currentTime << ", ans = " << maxAns << endl;
            }
            currentAns += (((mp[t.x][t.y] | getCol(t.c)) == tgt) - (mp[t.x][t.y] == tgt));
            mp[t.x][t.y] |= getCol(t.c);
            for(int i = 0; i < 8; i++){
                if(!(t.x + dirs[i][0] < 0 || t.x + dirs[i][0] >= N || t.y + dirs[i][1] < 0 || t.y + dirs[i][1] >= N)){
                    if(t.c == 'Y' && !yvis[t.x + dirs[i][0]][t.y + dirs[i][1]]){
                        push(Obj(t.x + dirs[i][0], t.y + dirs[i][1], t.c, t.time + 1));
                        yvis[t.x + dirs[i][0]][t.y + dirs[i][1]] = true;
                        //cout << "PUSHING COLOUR TO (" << t.x + dirs[i][0] <<", " << t.y + dirs[i][1] << ") WITH COLOUR " << t.c << endl;
                    } else if(t.c == 'R' && !rvis[t.x + dirs[i][0]][t.y + dirs[i][1]]){
                        push(Obj(t.x + dirs[i][0], t.y + dirs[i][1], t.c, t.time + 1));
                        rvis[t.x + dirs[i][0]][t.y + dirs[i][1]] = true;
                        //cout << "PUSHING COLOUR TO (" << t.x + dirs[i][0] <<", " << t.y + dirs[i][1] << ") WITH COLOUR " << t.c << endl;
                    } else if(t.c == 'B' && !bvis[t.x + dirs[i][0]][t.y + dirs[i][1]]){
                        push(Obj(t.x + dirs[i][0], t.y + dirs[i][1], t.c, t.time + 1));
                        bvis[t.x + dirs[i][0]][t.y + dirs[i][1]] = true;
                        //cout << "PUSHING COLOUR TO (" << t.x + dirs[i][0] <<", " << t.y + dirs[i][1] << ") WITH COLOUR " << t.c << endl;
                    }
                }
            }
            //cout << head << endl;
        }
        //cout << zz << ", " << Tt << endl;
        cout << maxAns << endl;
        //cout << cnt << endl;
        if(zz == Tt - 1) return 0;
    }
}
