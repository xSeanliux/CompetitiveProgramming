#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

int N, Q;
double _m, _b, x;
double INF = 2147483647;

class Line{
public:
    double m, b, lastX;
    double interX(const Line a){
        return (a.b - this->b)/(this->m - a.m);
    }
    double valAt(double x){
        return x * m + b;
    }
    Line(double m, double b): m(m), b(b){
        lastX = -INF;
    }
};

bool cmp_M(const Line a, const Line b){
    return a.m < b.m;
}

pair<Line, Line> getTopTwo(stack<Line> stk){
    Line a = stk.top();
    stk.pop();
    Line b = stk.top();
    return pair<Line, Line>(a, b);
}

vector<Line> lines;
vector<double> xCoords;
stack<Line> stk;

int main(){
    cin >> N;
    while(N--){
        cin >> _m >> _b;
        lines.push_back(Line(_m, _b));
    }
    sort(lines.begin(), lines.end(), cmp_M);
    lines[1].lastX = lines[1].interX(lines[0]);
    stk.push(lines[0]); stk.push(lines[1]);
    for(int i = 2; i < lines.size(); i++){
        Line top = lines[i];
        printf("Line %d: y = %lfx + %lf\n", i, top.m, top.b);
        if(stk.size() >= 2){
            pair<Line, Line> toptwo = getTopTwo(stk);
            printf("Intersection with 1 : %lf, Intersection with 2: %lf", top.interX(toptwo.first), top.interX(toptwo.second));
            while(stk.size() >= 2 && top.interX(toptwo.second) > top.interX(toptwo.first)){
                cout << "POP" << endl;
                stk.pop();
                if(stk.size() >= 2)
                    toptwo = getTopTwo(stk);
            }
        }
        top.lastX = top.interX(stk.top());
        stk.push(top);
    }
    while(stk.size()){
        xCoords.push_back(stk.top().lastX);
        printf("lastX: %lf\n", stk.top().lastX);
        stk.pop();
    }
}

