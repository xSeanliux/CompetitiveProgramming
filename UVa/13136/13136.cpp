#include <iostream>
#include <set>
#include <utility>
#include <vector>
#define ft pair<int, pair<int, pair<int, int> > >
using namespace std;



int T, a, b, c, S, newA, newB, newC;;
long long int n;
ft mp(int a, int b, int c, int d){
    return {a, {b, {c, d}}};
}

set <ft> st;
vector<ft> vec;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> a >> b >> c;
        st.clear();
        vec.clear();
        S = 0;
        if(!n){
            cout << 0 << endl;
            continue;
        }
        a %= 10, b %= 10, c %= 10;
        newA = (4*a - 3*b - 3*c + 100) % 10;
        newB = (5*a - 4*b - 4*c + 100) % 10;
        newC = (b - a + 100) % 10;
        a = newA, b = newB, c = newC;
        S += (a + b + c) % 10; S %= 10;
        ft current = mp(a, b, c, S);
        while(!st.count(current)){
            //printf("%d %d %d %d\n", a, b, c, S);
            vec.push_back(current);
            st.insert(current);
            newA = (4*a - 3*b - 3*c + 100) % 10;
            newB = (5*a - 4*b - 4*c + 100) % 10;
            newC = (b - a + 100) % 10;
            a = newA, b = newB, c = newC;
            S += (a + b + c) % 10; S %= 10;
            current = mp(a, b, c, S);
        }
        //cout << "REP: " << vec.size() << endl;
        cout << vec[ (n - 1) % vec.size() ].second.second.second << endl;
    }
}
