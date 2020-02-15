#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n, m, k;

struct Step{
    int rep;
    string com;
    Step(){}
    Step(int r, string c): rep(r), com(c){}
};

vector<Step> steps;

int main(){
    cin >> n >> m >> k;
    if(4 * n * m - 2 * n - 2 * m < k){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int left = k;
    if(n == 1){
        if(m - 1 >= left){
            steps.emplace_back(left, "R");
            left = 0;
        } else {
            steps.emplace_back(m - 1, "R");
            left -= m - 1;
        }
        if(left) steps.emplace_back(left, "L");
        cout << steps.size() << endl;
        for(Step s : steps){
            cout << s.rep << " " << s.com << endl;
        }
        return 0;
    }
    if(m == 1){
        if(n - 1 >= left){
            steps.emplace_back(left, "D");
            left = 0;
        } else {
            steps.emplace_back(n - 1, "D");
            left -= n - 1;
        }
        if(left) steps.emplace_back(left, "U");
        cout << steps.size() << endl;
        for(Step s : steps){
            cout << s.rep << " " << s.com << endl;
        }
        return 0;
    }
    for(int i = 0; (i < m - 1) && left; i++){
        if((n - 1) * 3 >= left){
            if(left >= 3) steps.emplace_back(left / 3, "DRL");
            left %= 3;
            if(left == 1) steps.emplace_back(1, "D");
            else if(left == 2) steps.emplace_back(1, "DR");
            left = 0;
            break;
        } else {
            steps.emplace_back((n - 1), "DRL");
            left -= (n - 1) * 3;
        }
        if(n - 1 >= left){
            steps.emplace_back(left, "U");
            left = 0;
            break;
        } else {
            steps.emplace_back(n - 1, "U");
            left -= n - 1;
        }
        if(!left) break;
        steps.emplace_back(1, "R");
        left--;
    }
    //cout << "Out, left = " << left << endl;
    if(left){
        if(n - 1 > left){
            steps.emplace_back(left, "D");
            left = 0;
        } else {
            steps.emplace_back(n - 1, "D");
            left -= n - 1;
        }
    }
    if(left){
        if(n - 1 > left){
            steps.emplace_back(left, "U");
            left = 0;
        } else {
            steps.emplace_back(n - 1, "U");
            left -= n - 1;
        }
    }
    if(left){
        if(m - 1 > left){
            steps.emplace_back(left, "L");
            left = 0;
        } else {
            steps.emplace_back(m - 1, "L");
            left -= m - 1;
        }
    }
    cout << steps.size() << endl;
    for(Step s : steps){
        cout << s.rep << " " << s.com << endl;
    }
}
