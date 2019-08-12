#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
typedef int lli;

lli t, n, _x, _y;
pair<lli, lli> points[1000000];

lli gcd(lli a, lli b){
    return b ? gcd(b, a % b) : a;
}

string getSlope(pair<lli, lli> a, pair<lli, lli> b){
    //cout << "in getslope" << endl;
    if(a.first == b.first) return "VERT";
    if(a.second == b.second) return "HORIZ";
    lli dx = a.first - b.first, dy = a.second - b.second, g = gcd(abs(dy), abs(dx));
    dx /= g; dy /= g;
    string res;
    res += to_string(dy);
    res += '/';
    res += to_string(dx);
    return res;
}

unordered_set<string> hasRep, slopes;
string _s;
bool isSafe;

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        //cout << "N = " << n << endl;
        isSafe = true;
        hasRep.clear();
        int reps = 0;
        for(int i = 0; i < n; i++){
            cin >> _x >> _y;
            _s = to_string(_x) + '/' + to_string(_y);
            if(hasRep.count(_s)){
                i--;
                n--;
            } else hasRep.insert(_s);
            points[i] = pair<lli, lli>(_x, _y);
        }
        if(n < 3){ //less than 3 unique points
            puts("Safe");
            continue;
        }
        sort(points, points + n);
        //cout << "Finished sorting " << endl;
        for(int i = 0; i < n && isSafe; i++){
            slopes.clear();
            //cout << "Hey" << endl;
            for(int j = i + 1; j < n && isSafe; j++){
                _s = getSlope(points[i], points[j]);
                //cout << _s << endl;
                if(slopes.count(_s)){
                    isSafe = false;
                    break;
                } else slopes.insert(_s);
            }
        }
        if(isSafe){
            puts("Safe");
        } else {
            puts("Dangerous");
        }
    }

}
