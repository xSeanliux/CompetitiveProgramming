#include <iostream>
#include <string.h>
#include <math.h>
#include <set>
using namespace std;

string s1, s2;

int main(){
    cin >> s1 >> s2;
    int h1 = stoi(s1.substr(0, 2)), m1 = stoi(s1.substr(3, 2));
    int h2 = stoi(s2.substr(0, 2)), m2 = stoi(s2.substr(3, 2));
    int time = (60*(h1 + h2) + (m1 + m2)) / 2;
    printf("%02d:%02d\n", time/60, time % 60);
}
